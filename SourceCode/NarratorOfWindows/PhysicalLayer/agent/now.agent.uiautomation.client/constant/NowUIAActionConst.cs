using System;

namespace now.agent.uiautomation.client.constant
{
    /// <summary>
    /// define name of actions
    /// </summary>
    sealed class NowUIAActionConst
    {
        public static readonly String UIA_ACTION_GET_PROPERTY               = "getproperty";
        public static readonly String UIA_ACTION_GET_ELEMENT_AT_POINT       = "getelementatpoint";
        public static readonly String UIA_ACTION_GETSTATUS                  = "getstatus";
        public static readonly String UIA_ACTION_GET_WINDOW_BY_TITLE        = "getwindowbytitle";
        public static readonly String UIA_ACTION_GET_CONTROL_BY_CONDITION   = "getcontrolbycondition";
        public static readonly String UIA_ACTION_BRING_WINDOW_TO_TOP        = "bringwindowtotop";
        public static readonly String UIA_ACTION_CLEAR_CACHE                = "clearcache";
        public static readonly String UIA_ACTION_SET_VALUE                  = "setvalue";
        public static readonly String UIA_ACTION_SCROLL_INTO_VIEW           = "scrollintoview";
    }

    sealed class NowUIAPropertyDefine
    {
        public static readonly String UIA_PROP_SIGNATURE        = "signature";
        public static readonly String UIA_PROP_PROPERTY_NAME    = "propertyname";
        public static readonly String UIA_PROP_POINT_X          = "x";
        public static readonly String UIA_PROP_POINT_Y          = "y";
        public static readonly String UIA_PROP_WINDOW_TITLE     = "windowtitle";
        public static readonly String UIA_PROP_WINDOW_HANDLE    = "windowhandle";
        public static readonly String UIA_PROP_DATA             = "propertydata";
        public static readonly String UIA_PROP_VALUE            = "value";
    }
}
