using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Automation;

namespace now.agent.uiautomation.client
{
    public class NowUIADefine
    {
        public static readonly int NOW_OK       =   0;
        public static readonly int NOW_FALSE    =   -1;
    }

    public class NowUIProperty
    {
        public static readonly String NOW_PROP_ACCELERATOR_KEY      = "AcceleratorKeyProperty";
        public static readonly String NOW_PROP_ACCESS_KEY           = "AccessKeyProperty";
        public static readonly String NOW_PROP_AUTOMATION_ID        = "AutomationIdProperty";
        public static readonly String NOW_PROP_BOUNDING_RECTANGLE   = "BoundingRectangleProperty";
        public static readonly String NOW_PROP_CLASS_NAME           = "ClassNameProperty";
        public static readonly String NOW_PROP_CLICKABLE_POINT      = "ClickablePointProperty";
        public static readonly String NOW_PROP_CONTROL_TYPE         = "ControlTypeProperty";
        public static readonly String NOW_PROP_CULTURE              = "CultureProperty";
        public static readonly String NOW_PROP_FRAMEWORK_ID         = "FrameworkIdProperty";
        public static readonly String NOW_PROP_HAS_KEYBOARD_FOCUS   = "HasKeyboardFocusProperty";
        public static readonly String NOW_PROP_HELP_TEXT            = "HelpTextProperty";
        public static readonly String NOW_PROP_IS_CONTENT_ELEMENT   = "IsContentElementProperty";
        public static readonly String NOW_PROP_IS_CONTROL_ELEMENT   = "IsControlElementProperty";
        public static readonly String NOW_PROP_IS_ENABLED           = "IsEnabledProperty";
        public static readonly String NOW_PROP_IS_KEYBOARD_FOCUSABLE = "IsKeyboardFocusableProperty";
        public static readonly String NOW_PROP_IS_OFF_SCREEN        = "IsOffscreenProperty";
        public static readonly String NOW_PROP_IS_PASSWORD          = "IsPasswordProperty";
        public static readonly String NOW_PROP_IS_REQUIRED_FOR_FORM = "IsRequiredForFormProperty";
        public static readonly String NOW_PROP_ITEM_STATUS          = "ItemStatusProperty";
        public static readonly String NOW_PROP_ITEM_TYPE            = "ItemTypeProperty";
        public static readonly String NOW_PROP_LABELED_BY           = "LabeledByProperty";
        public static readonly String NOW_PROP_LOCALIZED_CONTROL_TYPE = "LocalizedControlTypeProperty";
        public static readonly String NOW_PROP_NAME                 = "NameProperty";
        public static readonly String NOW_PROP_NATIVE_WINDOW_HANDLE = "NativeWindowHandleProperty";
        public static readonly String NOW_PROP_ORIENTATION          = "OrientationProperty";
        public static readonly String NOW_PROP_PROCESS_ID           = "ProcessIdProperty";
        public static readonly String NOW_PROP_RUNTIME_ID           = "RuntimeIdProperty";
    }
}
