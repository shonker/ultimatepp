#include "MIValue.h"

static MIValue &NullMIValue(void)
{
	static MIValue v;
	return v;
}

static MIValue &ErrorMIValue(String const &msg)
{
	static MIValue v;
	v.SetError(msg);
	return v;
}

bool MIValue::expect(String const &where, char exp, int i, String const &s)
{
	if(s[i] == exp)
		return true;
	int start = i - 30;
	if(start < 0)
		start = 0;
	if(!s[i])
		SetError(Format(where + " : Expected '%c', got end of string at pos %d around '%s'", exp, i, s.Mid(start, 60)));
	else
		SetError(Format(where + " : Expected '%c', got '%c' at pos %d in '%s'", exp, s[i], i, s.Mid(start, 60)));
	return false;
}

int MIValue::ParsePair(String &name, MIValue &val, String const &s, int i)
{
	name.Clear();
	val.Clear();
	while(s[i] && isspace(s[i]))
		i++;
	if(!s[i])
	{
		SetError("ParsePair:Unexpected end of string");
		return i;
	}
	
	// is starting wirh '[' or '{' take it as a value with empty name
	if(s[i] == '{' || s[i] == '[')
		name = "";
	else
	{
		int aCount = 0;
		while(s[i] && ((s[i] != '=' && s[i] != '}' && s[i] != ']') || aCount))
		{
			name.Cat(s[i]);
			if(s[i] == '<')
				aCount++;
			else if(s[i] == '>')
				aCount--;
			i++;
			
			// skip blanks if not inside <>
			if(!aCount)
				while(s[i] && isspace(s[i]))
					i++;
		}
		while(s[i] && isspace(s[i]))
			i++;

		if(s[i] != '=')
			return i;
		i++;

		while(s[i] && isspace(s[i]))
			i++;
	}
	switch(s[i])
	{
		case '"':
			i = val.ParseString(s, i);
			break;
		break;
		
		case '[':
			i = val.ParseArray(s, i);
			break;
			
		case '{':
			i = val.ParseTuple(s, i);
			break;
			
		default:
			i = val.ParseUnquotedString(s, i);
			break;
	}

	return i;
}

int MIValue::ParseTuple(String const &s, int i)
{
	Clear();
	type = MITuple;
	
	// drop opening delimiter
	if(!expect("ParseTuple", '{', i, s))
		return s.GetCount();
	i++;
	while(s[i] && s[i] != '}')
	{
		while(s[i] && isspace(s[i]))
			i++;
		String name;
		MIValue val;
		i = ParsePair(name, val, s, i);
		tuple.Add(name, val);
		while(s[i] && isspace(s[i]))
			i++;
		if(s[i] == '}')
			break;
		if(!expect("ParseTuple", ',', i, s))
			return s.GetCount();
		i++;
	}

	return i + 1;
}

int MIValue::ParseArray(String const &s, int i)
{
	Clear();
	type = MIArray;
	
	// drop opening delimiter
	if(!expect("ParseArray", '[', i, s))
		return s.GetCount();
	i++;
	while(s[i] && isspace(s[i]))
		i++;
	while(s[i] && s[i] != ']')
	{
		while(s[i] && isspace(s[i]))
			i++;
		String name;
		MIValue val;
		if(s[i] == '[')
			i = val.ParseArray(s, i);
		else if(s[i] == '{')
			i = val.ParseTuple(s, i);
		else if(s[i] == '"')
			i = val.ParseString(s, i);
		else if(s[i] == '<')
			i = val.ParseAngle(s, i);
		else
			i = ParsePair(name, val, s, i);
		array.Add(val);
		while(s[i] && isspace(s[i]))
			i++;
		if(s[i] == ']')
			break;
		if(!expect("ParseArray", ',', i, s))
			return s.GetCount();
		i++;
	}
	return i + 1;
}

int MIValue::ParseString(String const &s, int i)
{
	Clear();
	type = MIString;

	char c;
	if(!expect("ParseString", '"', i, s))
		return s.GetCount();
	i++;
	while( (c = s[i++]) != 0)
	{
		// verbatim if escaped
		if(c == '\\')
			string.Cat(s[i++]);
		else if(c == '"')
			break;
		else
			string.Cat(c);
	}
	if(!expect("ParseString", '"', i-1, s))
		return s.GetCount();

	return i;
}

int MIValue::ParseAngle(String const &s, int i)
{
	Clear();
	type = MIString;
	int aCount = 0;

	char c;
	if(!expect("ParseAngle", '<', i, s))
		return s.GetCount();
	string = "<";
	aCount++;
	i++;
	while( (c = s[i++]) != 0)
	{
		// verbatim if escaped
		if(c == '\\')
			string.Cat(s[i++]);
		else if(c == '>' && !--aCount)
			break;
		else
			string.Cat(c);
		if(c == '<')
			aCount++;
	}
	if(!expect("ParseAngle", '"', i-1, s))
		return s.GetCount();
	string.Cat('>');

	return i;
}

// sigh
static bool comma(String const &s, int i)
{
	if(s[i] != ',')
		return false;
	if(!i)
		return true;
	if(IsDigit(s[i-1]) && IsDigit(s[i+1]))
		return false;
	return true;
}

// we can hava a non-quoted string... so we read up
// to terminator, which can be '}', ']' or ','
int MIValue::ParseUnquotedString(String const &s, int i)
{
	String valStr;
	int aCount = 0;
	bool inQuote = false;
	while(s[i] && ((s[i] != '=' && s[i] != '}' && s[i] != ']' && !comma(s, i)) || inQuote || aCount))
	{
		valStr.Cat(s[i]);
		if(s[i] == '\\')
		{
			i++;
			if(s[i])
				valStr.Cat(s[i++]);
			continue;
		}
		if(s[i] == '<' && !inQuote)
			aCount++;
		else if(s[i] == '>' && !inQuote)
			aCount--;
		else if(s[i] == '"' && !aCount)
			inQuote = !inQuote;
		i++;
	}
	type = MIString;
	string = valStr;

	return i;
}

int MIValue::Parse(String const &s, int i)
{
	// if starts with '"', it's a string
	// if starts with '[', it's an array
	// if starts with '{', it's a tuple
	// otherwise, it can be a sequence of pair name="value" which is stored like a tuple
	// latter case is an example o bad design of MI interface....
	Clear();
	while(s[i] && isspace(s[i]))
		i++;
	if(s[i] == '"')
		return ParseString(s, i);
	else if(s[i] == '<')
		return ParseAngle(s, i);
	else if(s[i] == '[')
		return ParseArray(s, i);
	else if(s[i] == '{')
		return ParseTuple(s, i);
	else
	{
		String name;
		MIValue val;
		type = MITuple;
		while(s[i])
		{
			i = ParsePair(name, val, s, i);
			tuple.Add(name, val);
			while(s[i] && isspace(s[i]))
				i++;
			if(s[i] != ',')
				break;
			i++;
		}

		return i;
	}
}

MIValue &MIValue::operator=(pick_ MIValue &v)
{
	Clear();
	type = v.type;
	switch(type)
	{
		case MIString:
			string = v.string;
			break;
		case MIArray:
			array = v.array;
			break;
		case MITuple:
			tuple = v.tuple;
			break;
		default:
			SetError("Unknown MIValue type");
	}
	return *this;
}

MIValue::MIValue()
{
	Clear();
}

MIValue::MIValue(MIValue pick_ &v)
{
	Clear();
	type = v.type;
	switch(type)
	{
		case MIString:
			string = v.string;
			break;
		case MIArray:
			array = v.array;
			break;
		case MITuple:
			tuple = v.tuple;
			break;
		default:
			SetError("Unknown MIValue type");
	}
}

MIValue::MIValue(String const &s)
{
	Parse(s);
}

MIValue &MIValue::operator=(String const &s)
{
	Parse(s);
	return *this;
}

void MIValue::Clear()
{
	type = MIString;
	string = "";
	array.Clear();
	tuple.Clear();
}

// sets value to an error condition
MIValue &MIValue::SetError(String const &msg)
{
	type = MIString;
	string = "error:" + msg;
	return *this;
}

// check if value contains an error
bool MIValue::IsError(void) const
{
	return type == MIString && string.StartsWith("error:");
}
		
// check for emptyness
bool MIValue::IsEmpty(void) const
{
	return type == MIString && string == "";
}

// simple accessors
int MIValue::GetCount(void) const
{
	if(IsError())
		return 0;
	if(type == MIArray)
		return array.GetCount();
	else if(type == MITuple)
		return tuple.GetCount();
	else
		return string.GetCount();
}

int MIValue::Find(const char *key) const
{
	if(type != MITuple)
		return -1;
	return tuple.Find(key);
}

MIValue &MIValue::Get(int i)
{
	if(IsError())
		return *this;
	if(type == MIArray)
		return array[i];
	if(type == MITuple)
		return tuple[i];
	return ErrorMIValue("Not an Array value type");
}

MIValue const &MIValue::Get(int i) const
{
	if(IsError())
		return *this;
	if(type == MIArray)
		return array[i];
	if(type == MITuple)
		return tuple[i];
	return ErrorMIValue("Not an Array value type");
}

MIValue &MIValue::Get(const char *key)
{
	if(type != MITuple)
		return ErrorMIValue("Not a Tuple value type");
	if(tuple.Find(key) < 0)
		return ErrorMIValue(String("key '") + key + "' not found");
	return tuple.Get(key);
}

MIValue const &MIValue::Get(const char *key) const
{
	if(type != MITuple)
		return ErrorMIValue("Not a Tuple value type");
	if(tuple.Find(key) < 0)
		return ErrorMIValue(String("key '") + key + "' not found");
	return tuple.Get(key);
}

String &MIValue::Get(void)
{
	if(type != MIString)
		return ErrorMIValue("Not a String value type");
	return string;
}
		
String const &MIValue::Get(void) const
{
	if(type != MIString)
		return ErrorMIValue("Not a String value type");
	return string;
}
		
// tuple string member accessor with default value if not found
String MIValue::Get(const char *key, const char *def) const
{
	if(type != MITuple)
		return  ErrorMIValue("Not a Tuple value type");
	int i = tuple.Find(key);
	if(i >= 0)
	{
		if(tuple[i].type != MIString)
			return def;
		return tuple[i].Get();
	}
	else
		return def;
}

// gets key by index for tuple values
String MIValue::GetKey(int idx) const
{
	if(type != MITuple)
		return  ErrorMIValue("Not a Tuple value type");
	return tuple.GetKey(idx);
}

void MIValue::Set(String const &s)
{
	Clear();
	type = MIString;
	string = s;
}

// data dump
String MIValue::Dump(int level) const
{
	String spacer(' ', level);
	switch(type)
	{
		case MIString:
			return spacer + "<STRING>" + string;

		case MITuple:
		{
			String s = spacer + "<TUPLE>" + "{\n";
			level += 4;
			spacer = String(' ', level);
			for(int i = 0; i < tuple.GetCount(); i++)
			{
				String s1 = spacer + tuple.GetKey(i) + "=";
				s += s1;
				MIValue const &val = tuple[i];
				if(val.type == MIString)
					s += val.Dump();
				else
				{
					s += '\n' + val.Dump(level + 4);
					s = s.Left(s.GetCount()-1);
				}
				if(i < tuple.GetCount() - 1)
					s += ',';
				s += '\n';
			}
			level -= 4;
			spacer = String(' ', level);
			s += spacer + "}\n";
			return s;
		}

		case MIArray:
		{
			String s = spacer + "<ARRAY>" + "[ \n";
			level += 4;
			for(int i = 0; i < array.GetCount(); i++)
			{
				MIValue const &val = array[i];
				s += val.Dump(level);
				if(val.type != MIString)
					s = s.Left(s.GetCount()-1);
				if(i < array.GetCount() - 1)
					s += ',';
				s += '\n';
			}
			s += spacer + "]\n";
			return s;
		}
		
		default:
			return spacer + "*UNKNOWN MIVALUE TYPE*";
	}
}

// finds breakpoint data given file and line
MIValue &MIValue::FindBreakpoint(String const &file, int line)
{
	MIValue &body = Get("body");
	if(body.IsError() || !body.IsArray())
		return NullMIValue();
	for(int i = 0; i < body.GetCount(); i++)
	{
		MIValue &bp = body[i];
		if(bp.IsError() || !bp.IsTuple())
			return NullMIValue();
		if(bp["file"] == file && atoi(bp["line"].Get()) == line)
			return bp;
	}
	return NullMIValue();
}

static String PackName(String const &name)
{
	String res;
	const char *c = ~name;
	while(*c)
	{
		if(!IsSpace(*c))
			res.Cat(*c);
		c++;
	}
	return res;
}

// packs names inside tuples -- to make type recognition easy
void MIValue::PackNames(void)
{
	if(type == MITuple)
	{
		for(int i = 0; i < tuple.GetCount(); i++)
		{
			tuple.SetKey(i, PackName(tuple.GetKey(i)));
			tuple[i].PackNames();
		}
	}
	else if(type == MIArray)
	{
		for(int i = 0; i < array.GetCount(); i++)
			array[i].PackNames();
	}
}
