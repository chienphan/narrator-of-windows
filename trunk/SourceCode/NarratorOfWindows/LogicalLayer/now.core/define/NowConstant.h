#ifndef _NOW_CONSTANT_H_
#define _NOW_CONSTANT_H_

//constant define
#define NOW_OK		0
#define NOW_FALSE	-1
#define NOW_MAXLENGTH 256
#define NOW_SUCCEED(x) (x>=0)
//#define CREATE_WSTRING(x) L"x"

#define NOW_DEBUG_DIRECTORY "NOW_DEBUG_DIRECTORY"
#define NOW_DEBUG_MODE		"NOW_DEBUG_MODE"

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

#define NOW_PROP_ACCELERATOR_KEY		"AcceleratorKeyProperty"
#define NOW_PROP_ACCESS_KEY				"AccessKeyProperty"
#define NOW_PROP_AUTOMATION_ID			"AutomationIdProperty"
#define NOW_PROP_BOUNDING_RECTANGLE		"BoundingRectangleProperty"
#define NOW_PROP_CLASS_NAME				"ClassNameProperty"
#define NOW_PROP_CLICKABLE_POINT		"ClickablePointProperty"
#define NOW_PROP_CONTROL_TYPE			"ControlTypeProperty"
#define NOW_PROP_CULTURE				"CultureProperty"
#define NOW_PROP_FRAMEWORK_ID           "FrameworkIdProperty"
#define NOW_PROP_HAS_KEYBOARD_FOCUS		"HasKeyboardFocusProperty"
#define NOW_PROP_HELP_TEXT				"HelpTextProperty"
#define NOW_PROP_IS_CONTENT_ELEMENT		"IsContentElementProperty"
#define NOW_PROP_IS_CONTROL_ELEMENT		"IsControlElementProperty"
#define NOW_PROP_IS_ENABLED				"IsEnabledProperty"
#define NOW_PROP_IS_KEYBOARD_FOCUSABLE	"IsKeyboardFocusableProperty"
#define NOW_PROP_IS_OFF_SCREEN			"IsOffscreenProperty"
#define NOW_PROP_IS_PASSWORD			"IsPasswordProperty"
#define NOW_PROP_IS_REQUIRED_FOR_FORM	"IsRequiredForFormProperty"
#define NOW_PROP_ITEM_STATUS			"ItemStatusProperty"
#define NOW_PROP_ITEM_TYPE				"ItemTypeProperty"
#define NOW_PROP_LABELED_BY				"LabeledByProperty"
#define NOW_PROP_LOCALIZED_CONTROL_TYPE	"LocalizedControlTypeProperty"
#define NOW_PROP_NAME					"NameProperty"
#define NOW_PROP_NATIVE_WINDOW_HANDLE	"NativeWindowHandleProperty"
#define NOW_PROP_ORIENTATION			"OrientationProperty"
#define NOW_PROP_PROCESS_ID				"ProcessIdProperty"
#define NOW_PROP_RUNTIME_ID				"RuntimeIdProperty"

#endif