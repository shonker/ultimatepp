const dword
#ifdef GUIPLATFORM_KEYCODES_INCLUDE
	#include GUIPLATFORM_KEYCODES_INCLUDE
#else
	GUIPLATFORM_KEYCODES
#endif

	K_CTRL_BACK      = K_CTRL|K_BACKSPACE,
	K_CTRL_BACKSPACE = K_CTRL|K_BACKSPACE,
	K_CTRL_TAB       = K_CTRL|K_TAB,
	K_CTRL_RETURN    = K_CTRL|K_ENTER,
	K_CTRL_ENTER     = K_CTRL|K_ENTER,
	K_CTRL_ESCAPE    = K_CTRL|K_ESCAPE,
	K_CTRL_SPACE     = K_CTRL|K_SPACE,
	K_CTRL_PRIOR     = K_CTRL|K_PAGEUP,
	K_CTRL_PAGEUP    = K_CTRL|K_PAGEUP,
	K_CTRL_NEXT      = K_CTRL|K_PAGEDOWN,
	K_CTRL_PAGEDOWN  = K_CTRL|K_PAGEDOWN,
	K_CTRL_END       = K_CTRL|K_END,
	K_CTRL_HOME      = K_CTRL|K_HOME,
	K_CTRL_LEFT      = K_CTRL|K_LEFT,
	K_CTRL_UP        = K_CTRL|K_UP,
	K_CTRL_RIGHT     = K_CTRL|K_RIGHT,
	K_CTRL_DOWN      = K_CTRL|K_DOWN,
	K_CTRL_INSERT    = K_CTRL|K_INSERT,
	K_CTRL_DELETE    = K_CTRL|K_DELETE,


	K_CTRL_NUMPAD0   = K_CTRL|K_NUMPAD0,
	K_CTRL_NUMPAD1   = K_CTRL|K_NUMPAD1,
	K_CTRL_NUMPAD2   = K_CTRL|K_NUMPAD2,
	K_CTRL_NUMPAD3   = K_CTRL|K_NUMPAD3,
	K_CTRL_NUMPAD4   = K_CTRL|K_NUMPAD4,
	K_CTRL_NUMPAD5   = K_CTRL|K_NUMPAD5,
	K_CTRL_NUMPAD6   = K_CTRL|K_NUMPAD6,
	K_CTRL_NUMPAD7   = K_CTRL|K_NUMPAD7,
	K_CTRL_NUMPAD8   = K_CTRL|K_NUMPAD8,
	K_CTRL_NUMPAD9   = K_CTRL|K_NUMPAD9,
	K_CTRL_MULTIPLY  = K_CTRL|K_MULTIPLY,
	K_CTRL_ADD       = K_CTRL|K_ADD,
	K_CTRL_SEPARATOR = K_CTRL|K_SEPARATOR,
	K_CTRL_SUBTRACT  = K_CTRL|K_SUBTRACT,
	K_CTRL_DECIMAL   = K_CTRL|K_DECIMAL,
	K_CTRL_DIVIDE    = K_CTRL|K_DIVIDE,

	K_CTRL_F1        = K_CTRL|K_F1,
	K_CTRL_F2        = K_CTRL|K_F2,
	K_CTRL_F3        = K_CTRL|K_F3,
	K_CTRL_F4        = K_CTRL|K_F4,
	K_CTRL_F5        = K_CTRL|K_F5,
	K_CTRL_F6        = K_CTRL|K_F6,
	K_CTRL_F7        = K_CTRL|K_F7,
	K_CTRL_F8        = K_CTRL|K_F8,
	K_CTRL_F9        = K_CTRL|K_F9,
	K_CTRL_F10       = K_CTRL|K_F10,
	K_CTRL_F11       = K_CTRL|K_F11,
	K_CTRL_F12       = K_CTRL|K_F12,
	K_CTRL_SCROLL    = K_CTRL|K_SCROLL,

	K_CTRL_A         = K_CTRL|K_A,
	K_CTRL_B         = K_CTRL|K_B,
	K_CTRL_C         = K_CTRL|K_C,
	K_CTRL_D         = K_CTRL|K_D,
	K_CTRL_E         = K_CTRL|K_E,
	K_CTRL_F         = K_CTRL|K_F,
	K_CTRL_G         = K_CTRL|K_G,
	K_CTRL_H         = K_CTRL|K_H,
	K_CTRL_I         = K_CTRL|K_I,
	K_CTRL_J         = K_CTRL|K_J,
	K_CTRL_K         = K_CTRL|K_K,
	K_CTRL_L         = K_CTRL|K_L,
	K_CTRL_M         = K_CTRL|K_M,
	K_CTRL_N         = K_CTRL|K_N,
	K_CTRL_O         = K_CTRL|K_O,
	K_CTRL_P         = K_CTRL|K_P,
	K_CTRL_Q         = K_CTRL|K_Q,
	K_CTRL_R         = K_CTRL|K_R,
	K_CTRL_S         = K_CTRL|K_S,
	K_CTRL_T         = K_CTRL|K_T,
	K_CTRL_U         = K_CTRL|K_U,
	K_CTRL_V         = K_CTRL|K_V,
	K_CTRL_W         = K_CTRL|K_W,
	K_CTRL_X         = K_CTRL|K_X,
	K_CTRL_Y         = K_CTRL|K_Y,
	K_CTRL_Z         = K_CTRL|K_Z,
	K_CTRL_0         = K_CTRL|K_0,
	K_CTRL_1         = K_CTRL|K_1,
	K_CTRL_2         = K_CTRL|K_2,
	K_CTRL_3         = K_CTRL|K_3,
	K_CTRL_4         = K_CTRL|K_4,
	K_CTRL_5         = K_CTRL|K_5,
	K_CTRL_6         = K_CTRL|K_6,
	K_CTRL_7         = K_CTRL|K_7,
	K_CTRL_8         = K_CTRL|K_8,
	K_CTRL_9         = K_CTRL|K_9,

	K_SHIFT_BACK      = K_SHIFT|K_BACKSPACE,
	K_SHIFT_BACKSPACE = K_SHIFT|K_BACKSPACE,
	K_SHIFT_TAB       = K_SHIFT|K_TAB,
	K_SHIFT_RETURN    = K_SHIFT|K_ENTER,
	K_SHIFT_ENTER     = K_SHIFT|K_ENTER,
	K_SHIFT_ESCAPE    = K_SHIFT|K_ESCAPE,
	K_SHIFT_SPACE     = K_SHIFT|K_SPACE,
	K_SHIFT_PRIOR     = K_SHIFT|K_PAGEUP,
	K_SHIFT_PAGEUP    = K_SHIFT|K_PAGEUP,
	K_SHIFT_NEXT      = K_SHIFT|K_PAGEDOWN,
	K_SHIFT_PAGEDOWN  = K_SHIFT|K_PAGEDOWN,
	K_SHIFT_END       = K_SHIFT|K_END,
	K_SHIFT_HOME      = K_SHIFT|K_HOME,
	K_SHIFT_LEFT      = K_SHIFT|K_LEFT,
	K_SHIFT_UP        = K_SHIFT|K_UP,
	K_SHIFT_RIGHT     = K_SHIFT|K_RIGHT,
	K_SHIFT_DOWN      = K_SHIFT|K_DOWN,
	K_SHIFT_INSERT    = K_SHIFT|K_INSERT,
	K_SHIFT_DELETE    = K_SHIFT|K_DELETE,

	K_SHIFT_NUMPAD0   = K_SHIFT|K_NUMPAD0,
	K_SHIFT_NUMPAD1   = K_SHIFT|K_NUMPAD1,
	K_SHIFT_NUMPAD2   = K_SHIFT|K_NUMPAD2,
	K_SHIFT_NUMPAD3   = K_SHIFT|K_NUMPAD3,
	K_SHIFT_NUMPAD4   = K_SHIFT|K_NUMPAD4,
	K_SHIFT_NUMPAD5   = K_SHIFT|K_NUMPAD5,
	K_SHIFT_NUMPAD6   = K_SHIFT|K_NUMPAD6,
	K_SHIFT_NUMPAD7   = K_SHIFT|K_NUMPAD7,
	K_SHIFT_NUMPAD8   = K_SHIFT|K_NUMPAD8,
	K_SHIFT_NUMPAD9   = K_SHIFT|K_NUMPAD9,
	K_SHIFT_MULTIPLY  = K_SHIFT|K_MULTIPLY,
	K_SHIFT_ADD       = K_SHIFT|K_ADD,
	K_SHIFT_SEPARATOR = K_SHIFT|K_SEPARATOR,
	K_SHIFT_SUBRACT   = K_SHIFT|K_SUBTRACT,
	K_SHIFT_DECIMAL   = K_SHIFT|K_DECIMAL,
	K_SHIFT_DIVIDE    = K_SHIFT|K_DIVIDE,
	K_SHIFT_F1        = K_SHIFT|K_F1,
	K_SHIFT_F2        = K_SHIFT|K_F2,
	K_SHIFT_F3        = K_SHIFT|K_F3,
	K_SHIFT_F4        = K_SHIFT|K_F4,
	K_SHIFT_F5        = K_SHIFT|K_F5,
	K_SHIFT_F6        = K_SHIFT|K_F6,
	K_SHIFT_F7        = K_SHIFT|K_F7,
	K_SHIFT_F8        = K_SHIFT|K_F8,
	K_SHIFT_F9        = K_SHIFT|K_F9,
	K_SHIFT_F10       = K_SHIFT|K_F10,
	K_SHIFT_F11       = K_SHIFT|K_F11,
	K_SHIFT_F12       = K_SHIFT|K_F12,
	K_SHIFT_SCROLL    = K_SHIFT|K_SCROLL,

	K_SHIFT_A         = K_SHIFT|K_A,
	K_SHIFT_B         = K_SHIFT|K_B,
	K_SHIFT_C         = K_SHIFT|K_C,
	K_SHIFT_D         = K_SHIFT|K_D,
	K_SHIFT_E         = K_SHIFT|K_E,
	K_SHIFT_F         = K_SHIFT|K_F,
	K_SHIFT_G         = K_SHIFT|K_G,
	K_SHIFT_H         = K_SHIFT|K_H,
	K_SHIFT_I         = K_SHIFT|K_I,
	K_SHIFT_J         = K_SHIFT|K_J,
	K_SHIFT_K         = K_SHIFT|K_K,
	K_SHIFT_L         = K_SHIFT|K_L,
	K_SHIFT_M         = K_SHIFT|K_M,
	K_SHIFT_N         = K_SHIFT|K_N,
	K_SHIFT_O         = K_SHIFT|K_O,
	K_SHIFT_P         = K_SHIFT|K_P,
	K_SHIFT_Q         = K_SHIFT|K_Q,
	K_SHIFT_R         = K_SHIFT|K_R,
	K_SHIFT_S         = K_SHIFT|K_S,
	K_SHIFT_T         = K_SHIFT|K_T,
	K_SHIFT_U         = K_SHIFT|K_U,
	K_SHIFT_V         = K_SHIFT|K_V,
	K_SHIFT_W         = K_SHIFT|K_W,
	K_SHIFT_X         = K_SHIFT|K_X,
	K_SHIFT_Y         = K_SHIFT|K_Y,
	K_SHIFT_Z         = K_SHIFT|K_Z,
	K_SHIFT_0         = K_SHIFT|K_0,
	K_SHIFT_1         = K_SHIFT|K_1,
	K_SHIFT_2         = K_SHIFT|K_2,
	K_SHIFT_3         = K_SHIFT|K_3,
	K_SHIFT_4         = K_SHIFT|K_4,
	K_SHIFT_5         = K_SHIFT|K_5,
	K_SHIFT_6         = K_SHIFT|K_6,
	K_SHIFT_7         = K_SHIFT|K_7,
	K_SHIFT_8         = K_SHIFT|K_8,
	K_SHIFT_9         = K_SHIFT|K_9,

	K_SHIFT_CTRL_BACK      = K_SHIFT_CTRL|K_BACKSPACE,
	K_SHIFT_CTRL_BACKSPACE = K_SHIFT_CTRL|K_BACKSPACE,
	K_SHIFT_CTRL_TAB       = K_SHIFT_CTRL|K_TAB,
	K_SHIFT_CTRL_RETURN    = K_SHIFT_CTRL|K_ENTER,
	K_SHIFT_CTRL_ENTER     = K_SHIFT_CTRL|K_ENTER,
	K_SHIFT_CTRL_ESCAPE    = K_SHIFT_CTRL|K_ESCAPE,
	K_SHIFT_CTRL_SPACE     = K_SHIFT_CTRL|K_SPACE,
	K_SHIFT_CTRL_PRIOR     = K_SHIFT_CTRL|K_PAGEUP,
	K_SHIFT_CTRL_PAGEUP    = K_SHIFT_CTRL|K_PAGEUP,
	K_SHIFT_CTRL_NEXT      = K_SHIFT_CTRL|K_PAGEDOWN,
	K_SHIFT_CTRL_PAGEDOWN  = K_SHIFT_CTRL|K_PAGEDOWN,
	K_SHIFT_CTRL_END       = K_SHIFT_CTRL|K_END,
	K_SHIFT_CTRL_HOME      = K_SHIFT_CTRL|K_HOME,
	K_SHIFT_CTRL_LEFT      = K_SHIFT_CTRL|K_LEFT,
	K_SHIFT_CTRL_UP        = K_SHIFT_CTRL|K_UP,
	K_SHIFT_CTRL_RIGHT     = K_SHIFT_CTRL|K_RIGHT,
	K_SHIFT_CTRL_DOWN      = K_SHIFT_CTRL|K_DOWN,
	K_SHIFT_CTRL_INSERT    = K_SHIFT_CTRL|K_INSERT,
	K_SHIFT_CTRL_DELETE    = K_SHIFT_CTRL|K_DELETE,
	K_SHIFT_CTRL_LBRACKET  = K_SHIFT_CTRL|219|K_DELTA,
	K_SHIFT_CTRL_RBRACKET  = K_SHIFT_CTRL|221|K_DELTA,

	K_SHIFT_CTRL_NUMPAD0   = K_SHIFT_CTRL|K_NUMPAD0,
	K_SHIFT_CTRL_NUMPAD1   = K_SHIFT_CTRL|K_NUMPAD1,
	K_SHIFT_CTRL_NUMPAD2   = K_SHIFT_CTRL|K_NUMPAD2,
	K_SHIFT_CTRL_NUMPAD3   = K_SHIFT_CTRL|K_NUMPAD3,
	K_SHIFT_CTRL_NUMPAD4   = K_SHIFT_CTRL|K_NUMPAD4,
	K_SHIFT_CTRL_NUMPAD5   = K_SHIFT_CTRL|K_NUMPAD5,
	K_SHIFT_CTRL_NUMPAD6   = K_SHIFT_CTRL|K_NUMPAD6,
	K_SHIFT_CTRL_NUMPAD7   = K_SHIFT_CTRL|K_NUMPAD7,
	K_SHIFT_CTRL_NUMPAD8   = K_SHIFT_CTRL|K_NUMPAD8,
	K_SHIFT_CTRL_NUMPAD9   = K_SHIFT_CTRL|K_NUMPAD9,
	K_SHIFT_CTRL_MULTIPLY  = K_SHIFT_CTRL|K_MULTIPLY,
	K_SHIFT_CTRL_ADD       = K_SHIFT_CTRL|K_ADD,
	K_SHIFT_CTRL_SEPARATOR = K_SHIFT_CTRL|K_SEPARATOR,
	K_SHIFT_CTRL_SUBRACT   = K_SHIFT_CTRL|K_SUBTRACT,
	K_SHIFT_CTRL_DECIMAL   = K_SHIFT_CTRL|K_DECIMAL,
	K_SHIFT_CTRL_DIVIDE    = K_SHIFT_CTRL|K_DIVIDE,
	K_SHIFT_CTRL_F1        = K_SHIFT_CTRL|K_F1,
	K_SHIFT_CTRL_F2        = K_SHIFT_CTRL|K_F2,
	K_SHIFT_CTRL_F3        = K_SHIFT_CTRL|K_F3,
	K_SHIFT_CTRL_F4        = K_SHIFT_CTRL|K_F4,
	K_SHIFT_CTRL_F5        = K_SHIFT_CTRL|K_F5,
	K_SHIFT_CTRL_F6        = K_SHIFT_CTRL|K_F6,
	K_SHIFT_CTRL_F7        = K_SHIFT_CTRL|K_F7,
	K_SHIFT_CTRL_F8        = K_SHIFT_CTRL|K_F8,
	K_SHIFT_CTRL_F9        = K_SHIFT_CTRL|K_F9,
	K_SHIFT_CTRL_F10       = K_SHIFT_CTRL|K_F10,
	K_SHIFT_CTRL_F11       = K_SHIFT_CTRL|K_F11,
	K_SHIFT_CTRL_F12       = K_SHIFT_CTRL|K_F12,
	K_SHIFT_CTRL_SCROLL    = K_SHIFT_CTRL|K_SCROLL,

	K_SHIFT_CTRL_A         = K_SHIFT_CTRL|K_A,
	K_SHIFT_CTRL_B         = K_SHIFT_CTRL|K_B,
	K_SHIFT_CTRL_C         = K_SHIFT_CTRL|K_C,
	K_SHIFT_CTRL_D         = K_SHIFT_CTRL|K_D,
	K_SHIFT_CTRL_E         = K_SHIFT_CTRL|K_E,
	K_SHIFT_CTRL_F         = K_SHIFT_CTRL|K_F,
	K_SHIFT_CTRL_G         = K_SHIFT_CTRL|K_G,
	K_SHIFT_CTRL_H         = K_SHIFT_CTRL|K_H,
	K_SHIFT_CTRL_I         = K_SHIFT_CTRL|K_I,
	K_SHIFT_CTRL_J         = K_SHIFT_CTRL|K_J,
	K_SHIFT_CTRL_K         = K_SHIFT_CTRL|K_K,
	K_SHIFT_CTRL_L         = K_SHIFT_CTRL|K_L,
	K_SHIFT_CTRL_M         = K_SHIFT_CTRL|K_M,
	K_SHIFT_CTRL_N         = K_SHIFT_CTRL|K_N,
	K_SHIFT_CTRL_O         = K_SHIFT_CTRL|K_O,
	K_SHIFT_CTRL_P         = K_SHIFT_CTRL|K_P,
	K_SHIFT_CTRL_Q         = K_SHIFT_CTRL|K_Q,
	K_SHIFT_CTRL_R         = K_SHIFT_CTRL|K_R,
	K_SHIFT_CTRL_S         = K_SHIFT_CTRL|K_S,
	K_SHIFT_CTRL_T         = K_SHIFT_CTRL|K_T,
	K_SHIFT_CTRL_U         = K_SHIFT_CTRL|K_U,
	K_SHIFT_CTRL_V         = K_SHIFT_CTRL|K_V,
	K_SHIFT_CTRL_W         = K_SHIFT_CTRL|K_W,
	K_SHIFT_CTRL_X         = K_SHIFT_CTRL|K_X,
	K_SHIFT_CTRL_Y         = K_SHIFT_CTRL|K_Y,
	K_SHIFT_CTRL_Z         = K_SHIFT_CTRL|K_Z,
	K_SHIFT_CTRL_0         = K_SHIFT_CTRL|K_0,
	K_SHIFT_CTRL_1         = K_SHIFT_CTRL|K_1,
	K_SHIFT_CTRL_2         = K_SHIFT_CTRL|K_2,
	K_SHIFT_CTRL_3         = K_SHIFT_CTRL|K_3,
	K_SHIFT_CTRL_4         = K_SHIFT_CTRL|K_4,
	K_SHIFT_CTRL_5         = K_SHIFT_CTRL|K_5,
	K_SHIFT_CTRL_6         = K_SHIFT_CTRL|K_6,
	K_SHIFT_CTRL_7         = K_SHIFT_CTRL|K_7,
	K_SHIFT_CTRL_8         = K_SHIFT_CTRL|K_8,
	K_SHIFT_CTRL_9         = K_SHIFT_CTRL|K_9,

	K_ALT_BACK      = K_ALT|K_BACKSPACE,
	K_ALT_BACKSPACE = K_ALT|K_BACKSPACE,
	K_ALT_TAB       = K_ALT|K_TAB,
	K_ALT_RETURN    = K_ALT|K_ENTER,
	K_ALT_ENTER     = K_ALT|K_ENTER,
	K_ALT_ESCAPE    = K_ALT|K_ESCAPE,
	K_ALT_SPACE     = K_ALT|K_SPACE,
	K_ALT_PRIOR     = K_ALT|K_PAGEUP,
	K_ALT_PAGEUP    = K_ALT|K_PAGEUP,
	K_ALT_NEXT      = K_ALT|K_PAGEDOWN,
	K_ALT_PAGEDOWN  = K_ALT|K_PAGEDOWN,
	K_ALT_END       = K_ALT|K_END,
	K_ALT_HOME      = K_ALT|K_HOME,
	K_ALT_LEFT      = K_ALT|K_LEFT,
	K_ALT_UP        = K_ALT|K_UP,
	K_ALT_RIGHT     = K_ALT|K_RIGHT,
	K_ALT_DOWN      = K_ALT|K_DOWN,
	K_ALT_INSERT    = K_ALT|K_INSERT,
	K_ALT_DELETE    = K_ALT|K_DELETE,

	K_ALT_NUMPAD0   = K_ALT|K_NUMPAD0,
	K_ALT_NUMPAD1   = K_ALT|K_NUMPAD1,
	K_ALT_NUMPAD2   = K_ALT|K_NUMPAD2,
	K_ALT_NUMPAD3   = K_ALT|K_NUMPAD3,
	K_ALT_NUMPAD4   = K_ALT|K_NUMPAD4,
	K_ALT_NUMPAD5   = K_ALT|K_NUMPAD5,
	K_ALT_NUMPAD6   = K_ALT|K_NUMPAD6,
	K_ALT_NUMPAD7   = K_ALT|K_NUMPAD7,
	K_ALT_NUMPAD8   = K_ALT|K_NUMPAD8,
	K_ALT_NUMPAD9   = K_ALT|K_NUMPAD9,
	K_ALT_MULTIPLY  = K_ALT|K_MULTIPLY,
	K_ALT_ADD       = K_ALT|K_ADD,
	K_ALT_SEPARATOR = K_ALT|K_SEPARATOR,
	K_ALT_SUBTRACT  = K_ALT|K_SUBTRACT,
	K_ALT_DECIMAL   = K_ALT|K_DECIMAL,
	K_ALT_DIVIDE    = K_ALT|K_DIVIDE,
	K_ALT_F1        = K_ALT|K_F1,
	K_ALT_F2        = K_ALT|K_F2,
	K_ALT_F3        = K_ALT|K_F3,
	K_ALT_F4        = K_ALT|K_F4,
	K_ALT_F5        = K_ALT|K_F5,
	K_ALT_F6        = K_ALT|K_F6,
	K_ALT_F7        = K_ALT|K_F7,
	K_ALT_F8        = K_ALT|K_F8,
	K_ALT_F9        = K_ALT|K_F9,
	K_ALT_F10       = K_ALT|K_F10,
	K_ALT_F11       = K_ALT|K_F11,
	K_ALT_F12       = K_ALT|K_F12,
	K_ALT_SCROLL    = K_ALT|K_SCROLL,

	K_ALT_A         = K_ALT|K_A,
	K_ALT_B         = K_ALT|K_B,
	K_ALT_C         = K_ALT|K_C,
	K_ALT_D         = K_ALT|K_D,
	K_ALT_E         = K_ALT|K_E,
	K_ALT_F         = K_ALT|K_F,
	K_ALT_G         = K_ALT|K_G,
	K_ALT_H         = K_ALT|K_H,
	K_ALT_I         = K_ALT|K_I,
	K_ALT_J         = K_ALT|K_J,
	K_ALT_K         = K_ALT|K_K,
	K_ALT_L         = K_ALT|K_L,
	K_ALT_M         = K_ALT|K_M,
	K_ALT_N         = K_ALT|K_N,
	K_ALT_O         = K_ALT|K_O,
	K_ALT_P         = K_ALT|K_P,
	K_ALT_Q         = K_ALT|K_Q,
	K_ALT_R         = K_ALT|K_R,
	K_ALT_S         = K_ALT|K_S,
	K_ALT_T         = K_ALT|K_T,
	K_ALT_U         = K_ALT|K_U,
	K_ALT_V         = K_ALT|K_V,
	K_ALT_W         = K_ALT|K_W,
	K_ALT_X         = K_ALT|K_X,
	K_ALT_Y         = K_ALT|K_Y,
	K_ALT_Z         = K_ALT|K_Z,
	K_ALT_0         = K_ALT|K_0,
	K_ALT_1         = K_ALT|K_1,
	K_ALT_2         = K_ALT|K_2,
	K_ALT_3         = K_ALT|K_3,
	K_ALT_4         = K_ALT|K_4,
	K_ALT_5         = K_ALT|K_5,
	K_ALT_6         = K_ALT|K_6,
	K_ALT_7         = K_ALT|K_7,
	K_ALT_8         = K_ALT|K_8,
	K_ALT_9         = K_ALT|K_9,

	K_CTRL_BREAK    = K_CTRL|K_BREAK
;
