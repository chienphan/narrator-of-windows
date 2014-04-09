using System;

namespace now.agent.uiautomation.client.constant
{
    /// <summary>
    /// define name of actions
    /// </summary>
    sealed class NowUIAActionConst
    {
        public static readonly String NOW_GET_PROPERTY = "getproperty";
        public static readonly String UIA_ACTION_GET_ELEMENT_AT_POINT = "getelementatpoint";
        public static readonly String UIA_ACTION_GETSTATUS = "getstatus";
    }

    sealed class NowUIAPropertyDefine
    {
        public static readonly String UIA_PROP_SIGNATURE = "signature";
        public static readonly String UIA_PROP_PROPERTY_NAME = "propertyname";
        public static readonly String UIA_PROP_POINT_X = "x";
        public static readonly String UIA_PROP_POINT_Y = "y";
    }
}
