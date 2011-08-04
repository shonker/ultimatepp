#include "Browser.h"

#define IMAGEFILE <ide/Browser/Topic.iml>
#define IMAGECLASS TopicImg
#include <Draw/iml_source.h>

TopicEditor::TopicEditor()
{
	SizePos();
	editor.InsertFrame(0, TopSeparatorFrame());
	editor.InsertFrame(1, tool);
	SetBar();
	Font tf = StdFont().Bold();
	int dcy = EditField::GetStdHeight(tf);
	title.SetFont(tf);
	right.Add(title.HSizePos(2, 2).TopPos(0, dcy));
	title.Tip("Topic title");
	title.NullText("Topic title", tf().Italic(), SColorDisabled());
	right.Add(editor.VSizePos(dcy + 4, 0).HSizePos());
	Add(left_right.Horz(topic, right));
	left_right.SetPos(1200);

	topic.NoRoundSize().Columns(1);

	topic.WhenSel = THISBACK(TopicCursor);
	topic.WhenBar = THISBACK(TopicMenu);
	topic.NoWantFocus();

	editor.SetPage(TopicPage());
	editor.WhenRefreshBar = THISBACK(SetBar);
	editor.WhenHyperlink = THISBACK(Hyperlink);

	editor.Disable();
	title.Disable();

	lastlang = LNG_ENGLISH;

	allfonts = false;

	editor.WhenLabel = THISBACK(Label);
	
	LoadFromGlobal(*this, "topic-editor");
}

TopicEditor::~TopicEditor()
{
	StoreToGlobal(*this, "topic-editor");
	Flush();
}

INITBLOCK {
	RegisterGlobalConfig("topic-editor");
}

void TopicEditor::Serialize(Stream& s)
{
	int version = 0;
	s / version;
	editor.SerializeSettings(s);
	s % left_right;
	topic.SerializeSettings(s);
	s % allfonts;
	SyncFonts();
}

void TopicEditor::SerializeEditPos(Stream& s)
{
	int version = 0;
	s / version;
	if(s.IsStoring()) {
		for(int i = 0; i < editstate.GetCount(); i++) {
			String fn = editstate.GetKey(i);
			if(!IsNull(fn) && FileExists(fn)) {
				s % fn;
				s % editstate[i].pos;
			}
		}
		String empty;
		s % empty;
	}
	else
		for(;;) {
			String fn;
			s % fn;
			if(IsNull(fn))
				break;
			s % editstate.GetAdd(fn).pos;
		}
	s % grouptopic;
	s % lastlang;
	s % lasttemplate;
}

void TopicEditor::ExportPdf()
{
	FileSel fs;
	fs.Type("PDF files", "*.pdf")
	  .AllFilesType()
	  .DefaultExt("pdf");
	if(!fs.ExecuteSaveAs("Output PDF file"))
		return;
	Size page = Size(3968, 6074);
	PdfDraw pdf(page + 400);
	::Print(pdf, editor.Get(), page);
	SaveFile(~fs, pdf.Finish());
}

void TopicEditor::ExportGroupPdf()
{
	String dir = SelectDirectory();
	if(IsNull(dir))
		return;
	SaveTopic();
	FindFile ff(AppendFileName(grouppath, "*.tpp"));
	while(ff) {
		Topic t = ReadTopic(LoadFile(AppendFileName(grouppath, ff.GetName())));
		if(!t.text.IsVoid()) {
			Size page = Size(3968, 6074);
			PdfDraw pdf(page + 400);
			::Print(pdf, ParseQTF(t.text), page);
			String pdfdata = pdf.Finish();
			String path = AppendFileName(dir, GetFileTitle(ff.GetName()) + ".pdf");
			if(LoadFile(path) != pdfdata)
				SaveFile(path, pdfdata);
		}
		ff.Next();
	}	
}

void TopicEditor::ExportHTML()
{
/*	String EncodeHtml(const RichText& text, Index<String>& css,
	                  const VectorMap<String, String>& links,
	                  const VectorMap<String, String>& labels,
	                  const String& path, const String& base = Null, Zoom z = Zoom(8, 40),
	                  const VectorMap<String, String>& escape = VectorMap<String, String>(),
	                  int imtolerance = 0);
	String AsCss(Index<String>& ss);
	SelectSaveFile("HTML files\t*.html\nAll files\t*.*", file);*/
}

void TopicEditor::ExportGroupHTML()
{
/*	String dir = SelectDirectory();
	if(IsNull(dir))
		return;
	SaveTopic();
	FindFile ff(AppendFileName(grouppath, "*.tpp"));
	while(ff) {
		Topic t = ReadTopic(LoadFile(AppendFileName(grouppath, ff.GetName())));
		if(!t.text.IsVoid()) {
			Size page = Size(3968, 6074);
			PdfDraw pdf(page + 400);
			::Print(pdf, ParseQTF(t.text), page);
			String pdfdata = pdf.Finish();
			String path = AppendFileName(dir, GetFileTitle(ff.GetName()) + ".pdf");
			if(LoadFile(path) != pdfdata)
				SaveFile(path, pdfdata);
		}
		ff.Next();
	}*/
}

void TopicEditor::Print()
{
	UPP::Print(editor.Get(), Size(3968, 6074), 0);
}

void TopicEditor::SyncFonts()
{
	Vector<int> ff;
	ff.Add(Font::ARIAL);
	ff.Add(Font::ROMAN);
	ff.Add(Font::COURIER);
	if(allfonts)
		for(int i = Font::COURIER + 1; i < Font::GetFaceCount(); i++)
			if(Font::GetFaceInfo(i) & Font::SCALEABLE)
				ff.Add(i);
	editor.FontFaces(ff);
}

void TopicEditor::AllFonts()
{
	allfonts = !allfonts;
	SyncFonts();
}

void TopicEditor::TopicMenu(Bar& bar)
{
	bar.Add("New topic..", THISBACK(NewTopic))
	   .Key(K_CTRL_N).Key(K_ALT_INSERT);
	bar.Add(topic.IsCursor(), "Move topic..", THISBACK(MoveTopic));
	bar.Add(topic.IsCursor(), "Delete topic", THISBACK(RemoveTopic))
	   .Key(K_ALT_DELETE);
	bar.Separator();
	bar.Add(topic.IsCursor() && GetFileTitle(topicpath) != "$.tpp",
	        "Save as template..", THISBACK(SaveAsTemplate));
	bar.Add(topic.IsCursor(), "Apply template stylesheet..", THISBACK(ApplyStylesheet));
	bar.Add("Apply template stylesheet to group..", THISBACK(ApplyStylesheetGroup));
	editor.StyleKeysTool(bar);
}

void TopicEditor::FileBar(Bar& bar)
{
	TopicMenu(bar);
	bar.Separator();
	bar.Add("Print", CtrlImg::print(), THISBACK(Print))
	   .Key(K_CTRL_P);
	bar.Add("Export to PDF..", THISBACK(ExportPdf));
	bar.Add("Export group  to PDF..", THISBACK(ExportGroupPdf));
	bar.Add("Export to HTML..", THISBACK(ExportPdf));
	bar.Add("Export group  to HTML..", THISBACK(ExportGroupPdf));
}

void TopicEditor::EditMenu(Bar& bar)
{
	FileBar(bar);
	bar.Separator();
	editor.CutTool(bar);
	editor.CopyTool(bar);
	editor.PasteTool(bar);
	editor.InsertImageTool(bar);
	bar.Separator();
	editor.UndoTool(bar);
	editor.RedoTool(bar);
	bar.Separator();
	editor.FindReplaceTool(bar);
	bar.Separator();
	bar.Add("All fonts", THISBACK(AllFonts))
	   .Check(allfonts);
	bar.Separator();
	bar.Add("Table", THISBACK(TableMenu));
}

void TopicEditor::FormatMenu(Bar& bar)
{
	editor.StyleTool(bar);
	bar.Separator();
	editor.FontTools(bar);
	bar.Separator();
	editor.InkTool(bar);
	editor.PaperTool(bar);
	bar.Separator();
	editor.LanguageTool(bar);
	editor.SpellCheckTool(bar);
	bar.Separator();
	editor.IndexEntryTool(bar);
	bar.Break();
	editor.HyperlinkTool(bar, 300, K_CTRL_H);
	bar.Separator();
	editor.ParaTools(bar);
}

void TopicEditor::TableMenu(Bar& bar)
{
	editor.TableTools(bar);
}

void CreateTopic(const char *fn, int lang, const String& ss)
{
	SaveFile(fn,  WriteTopic("", ParseQTF(ss + "[{_}%" + LNGAsText(lang) + " ")));
}

bool TopicEditor::NewTopicEx(const String& iname, const String& create)
{
	TopicDlg<WithNewTopicLayout<TopWindow> > d("New topic");
	d.lang <<= lastlang;
	if(iname.GetCount()) {
		int i = 0;
		do {
			String n = iname;
			if(i)
				n << i;
			d.topic <<= n;
			i++;
		}
		while(FileExists(AppendFileName(grouppath, d.GetName())));
	}

	Vector<String> path, name;
	ListTemplates(path, name);
	d.tmpl.Add(Null, "<none>");
	for(int i = 0; i < path.GetCount(); i++)
		d.tmpl.Add(path[i], name[i]);

	if(d.tmpl.HasKey(lasttemplate))
		d.tmpl <<= lasttemplate;
	else
		d.tmpl.GoBegin();

	d.ActiveFocus(d.topic);
	String fn;
	for(;;) {
		if(d.Run() != IDOK)
			return false;
		fn = AppendFileName(grouppath, d.GetName());
		if(!FileExists(fn))
			break;
		if(PromptYesNo("Topic already exists.&Do you want to rewrite it?"))
			break;
	}
	lasttemplate = ~d.tmpl;
	lastlang = ~d.lang;
	CreateTopic(fn, ~d.lang, IsNull(~d.tmpl) ? String() : ReadTopic(LoadFile((String)~d.tmpl)).text);
	Flush();
	Open(grouppath);
	Load(fn);
	SaveInc();
	topic.FindSetCursor(GetFileTitle(fn));
	editor.SetFocus();
	serial++;
	if(create.GetCount())
		InsertNew(create);
	return true;
}

void TopicEditor::NewTopic()
{
	NewTopicEx(Null, Null);
}

void TopicEditor::RemoveTopic()
{
	if(!topic.IsCursor() ||
	   !PromptYesNo("Delete topic [* " + DeQtf(topic.GetCurrentName()) + "] ?"))
		return;
	String p = GetCurrentTopicPath();
	int q = topic.GetCursor();
	Flush();
	DeleteFile(p);
	Open(grouppath);
	SaveInc();
	topic.SetCursor(q);
	if(q >= 0)
		editor.SetFocus();
	InvalidateTopicInfoPath(p);
}

void TopicEditor::SaveAsTemplate()
{
	TopicDlg<WithSaveTemplateLayout<TopWindow> > d("Save as template");
	d.lang <<= lastlang;
	Vector<String> ud = GetUppDirs();
	String p = GetCurrentTopicPath();
	for(int i = 0; i < ud.GetCount(); i++) {
		d.nest.Add(ud[i]);
		if(p.StartsWith(ud[i]))
			d.nest.SetIndex(i);
	}
	if(d.nest.GetIndex() < 0)
		d.nest.GoBegin();
	if(d.Execute() != IDOK || IsNull(~d.nest))
		return;
	SaveFile(AppendFileName(AppendFileName(~d.nest, "$.tpp"), d.GetName()),
	         WriteTopic((String)~title, editor.Get()));
}

void TopicEditor::SetBar()
{
	tool.Set(THISBACK(MainTool));
}

bool TopicEditor::Key(dword key, int cnt)
{
	switch(key) {
	case K_ALT_F10:
		FixTopic();
		return true;
	case K_ALT_UP:
		return topic.Key(K_UP, 0);
	case K_ALT_DOWN:
		return topic.Key(K_DOWN, 0);
	}
	return false;
}
