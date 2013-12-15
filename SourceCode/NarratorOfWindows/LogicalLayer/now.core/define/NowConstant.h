#ifndef _NOW_CONSTANT_H_
#define _NOW_CONSTANT_H_

//constant define
#define NOW_OK		0
#define NOW_FALSE	-1
#define NOW_MAXLENGTH 256
#define NOW_SUCCEED(x) (x>=0)
//#define CREATE_WSTRING(x) L"x"

#define NOW_STATE_VISIBLE		1
#define NOW_STATE_INVISIBLE		2
#define NOW_STATE_ENABLE		4
#define NOW_STATE_DISABLE		8
#define NOW_STATE_COLLAPSED		16
#define NOW_STATE_EXPANDED		32
#define NOW_STATE_CHECKED		64
#define NOW_STATE_UNCHECKED		128
#define NOW_STATE_SELECTED		256
#define NOW_STATE_UNSETECTED	512

#define NOW_LOGGER_NONE_MODE		0
#define NOW_LOGGER_DEBUGVIEW_MODE	1
#define NOW_LOGGER_FILE_MODE		2

#define NOW_PLUGIN_NAME_UIA "uiautomation"

#define NOW_CONTROL				"control"
#define NOW_CONTROL_BUTTON		"button"

#endif