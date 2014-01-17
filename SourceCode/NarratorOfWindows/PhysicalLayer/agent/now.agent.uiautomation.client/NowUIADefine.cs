using System;

namespace now.agent.uiautomation.client
{
    /// <summary>
    /// Define common constant
    /// </summary>
    public class NowUIADefine
    {
        public static readonly int NOW_OK       =   0;
        public static readonly int NOW_FALSE    =   -1;
    }

    public class NowUIAState
    {
        public static readonly int NOW_STATE_VISIBLE = 1;
        public static readonly int NOW_STATE_INVISIBLE = 2;
        public static readonly int NOW_STATE_ENABLE = 4;
        public static readonly int NOW_STATE_DISABLE = 8;
        public static readonly int NOW_STATE_COLLAPSED = 16;
        public static readonly int NOW_STATE_EXPANDED = 32;
        public static readonly int NOW_STATE_CHECKED = 64;
        public static readonly int NOW_STATE_UNCHECKED = 128;
        public static readonly int NOW_STATE_SELECTED = 256;
        public static readonly int NOW_STATE_UNSETECTED = 512;
        public static readonly int NOW_STATE_LEAF_NODE = 1024;
    }

    /// <summary>
    /// Define name of UI Automation property
    /// </summary>
    public class NowUIAProperty
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
        public static readonly String NOW_PROP_IS_SELECTED          = "IsSelectedProperty";
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
        public static readonly String NOW_PROP_IS_EXPANDED          = "IsExpandedProperty";
        public static readonly String NOW_PROP_IS_COLLAPSED         = "IsCollapsedProperty";
        public static readonly String NOW_PROP_IS_LEAF_NODE         = "IsLeafNodeProperty";
        public static readonly String NOW_PROP_IS_CHECKED           = "IsCheckProperty";
        public static readonly String NOW_PROP_IS_UNCHECKED         = "IsUncheckedProperty";
        public static readonly String NOW_PROP_IS_RADIO_BUTTON      = "IsRadioButtonProperty";
    }

    /// <summary>
    /// define environment variable
    /// </summary>
    public class NowUIAEnvironmentVariable
    {
        public static readonly String NOW_DEBUG_DIRECTORY   = "NOW_DEBUG_DIRECTORY";
        public static readonly String NOW_DEBUG_MODE        = "NOW_DEBUG_MODE";
    }

    /// <summary>
    /// define log mode
    /// </summary>
    public class NowLogMode
    {
        public static readonly int LOG_NONE = -1;
        public static readonly int LOG_DEBUG_VIEW = 0;
        public static readonly int LOG_FILE = 1;
    }

    /// <summary>
    /// define enable log mode
    /// </summary>
    public class NowEnvVariable
    {
        public static readonly String ENV_VARIABLE_LOG_ENABLE = "1";
        public static readonly String ENV_VARIABLE_LOG_DISABLE = "0";
    }
}
