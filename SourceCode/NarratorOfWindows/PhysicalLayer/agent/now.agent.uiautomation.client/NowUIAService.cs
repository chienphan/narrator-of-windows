using System;
using System.Collections.Generic;
using System.Windows.Automation;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.logger;

namespace now.agent.uiautomation.client
{
    public class NowUIAService
    {
        private static NowUIAService m_instance = null;
        private static Dictionary<String, Object> m_propMap = null;
        private static Dictionary<String, int> m_stateValMap = null;
        private static Dictionary<String, object> m_checkUIHaveStateMap = null;
        private static Dictionary<String, String> m_nameStateMap = null;

        private NowUIAService()
        {
            InitPropertiesMap();
        }

        /// <summary>
        /// Get Singleton instance of NowAutomationService
        /// </summary>
        /// <returns>NowAutomationService instance</returns>
        public static NowUIAService GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIAService();
            }
            return m_instance;
        }

        private void InitPropertiesMap()
        {
            m_propMap = new Dictionary<String, Object>();
            m_stateValMap = new Dictionary<string, int>();
            m_checkUIHaveStateMap = new Dictionary<string, object>();
            m_nameStateMap = new Dictionary<String, String>();


            m_propMap.Add(NowUIAProperty.NOW_PROP_ACCELERATOR_KEY, AutomationElement.AcceleratorKeyProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_ACCESS_KEY, AutomationElement.AccessKeyProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_AUTOMATION_ID, AutomationElement.AutomationIdProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_BOUNDING_RECTANGLE, AutomationElement.BoundingRectangleProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_CLASS_NAME, AutomationElement.ClassNameProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_CLICKABLE_POINT, AutomationElement.ClickablePointProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_CONTROL_TYPE, AutomationElement.ControlTypeProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_CULTURE, AutomationElement.CultureProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_FRAMEWORK_ID, AutomationElement.FrameworkIdProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_HAS_KEYBOARD_FOCUS, AutomationElement.HasKeyboardFocusProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_HELP_TEXT, AutomationElement.HelpTextProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_CONTENT_ELEMENT, AutomationElement.IsContentElementProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_CONTROL_ELEMENT, AutomationElement.IsControlElementProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_ENABLED, AutomationElement.IsEnabledProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_KEYBOARD_FOCUSABLE, AutomationElement.IsKeyboardFocusableProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_OFF_SCREEN, AutomationElement.IsOffscreenProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_PASSWORD, AutomationElement.IsPasswordProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_REQUIRED_FOR_FORM, AutomationElement.IsRequiredForFormProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_ITEM_STATUS, AutomationElement.ItemStatusProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_ITEM_TYPE, AutomationElement.ItemTypeProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_LABELED_BY, AutomationElement.LabeledByProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_LOCALIZED_CONTROL_TYPE, AutomationElement.LocalizedControlTypeProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_NAME, AutomationElement.NameProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_NATIVE_WINDOW_HANDLE, AutomationElement.NativeWindowHandleProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_ORIENTATION, AutomationElement.OrientationProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_PROCESS_ID, AutomationElement.ProcessIdProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_RUNTIME_ID, AutomationElement.RuntimeIdProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_SELECTED, SelectionItemPattern.IsSelectedProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_EXPANDED, ExpandCollapsePattern.ExpandCollapseStateProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_COLLAPSED, ExpandCollapsePattern.ExpandCollapseStateProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_LEAF_NODE, ExpandCollapsePattern.ExpandCollapseStateProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_CHECKED, TogglePattern.ToggleStateProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_UNCHECKED, TogglePattern.ToggleStateProperty);
            m_propMap.Add(NowUIAProperty.NOW_PROP_IS_VALUE, RangeValuePattern.ValueProperty);
           

            m_stateValMap.Add(NowUIAProperty.NOW_PROP_IS_SELECTED, NowUIAState.NOW_STATE_SELECTED);
            m_stateValMap.Add(NowUIAProperty.NOW_PROP_IS_COLLAPSED, NowUIAState.NOW_STATE_COLLAPSED);
            m_stateValMap.Add(NowUIAProperty.NOW_PROP_IS_EXPANDED, NowUIAState.NOW_STATE_EXPANDED);
            m_stateValMap.Add(NowUIAProperty.NOW_PROP_IS_LEAF_NODE, NowUIAState.NOW_STATE_LEAF_NODE);
            m_stateValMap.Add(NowUIAProperty.NOW_PROP_IS_CHECKED, NowUIAState.NOW_STATE_CHECKED);
            m_stateValMap.Add(NowUIAProperty.NOW_PROP_IS_UNCHECKED, NowUIAState.NOW_STATE_UNCHECKED);

            m_checkUIHaveStateMap.Add(NowUIAProperty.NOW_PROP_IS_SELECTED, AutomationElement.IsSelectionItemPatternAvailableProperty);
            m_checkUIHaveStateMap.Add(NowUIAProperty.NOW_PROP_IS_EXPANDED, AutomationElement.IsExpandCollapsePatternAvailableProperty);
            m_checkUIHaveStateMap.Add(NowUIAProperty.NOW_PROP_IS_COLLAPSED, AutomationElement.IsExpandCollapsePatternAvailableProperty);
            m_checkUIHaveStateMap.Add(NowUIAProperty.NOW_PROP_IS_LEAF_NODE, AutomationElement.IsExpandCollapsePatternAvailableProperty);
            m_checkUIHaveStateMap.Add(NowUIAProperty.NOW_PROP_IS_CHECKED, AutomationElement.IsTogglePatternAvailableProperty);
            m_checkUIHaveStateMap.Add(NowUIAProperty.NOW_PROP_IS_UNCHECKED, AutomationElement.IsTogglePatternAvailableProperty);

            m_nameStateMap.Add(NowUIAProperty.NOW_PROP_IS_SELECTED, "true");
            m_nameStateMap.Add(NowUIAProperty.NOW_PROP_IS_EXPANDED, "expanded");
            m_nameStateMap.Add(NowUIAProperty.NOW_PROP_IS_COLLAPSED, "collapsed");
            m_nameStateMap.Add(NowUIAProperty.NOW_PROP_IS_LEAF_NODE, "leafnode");
            m_nameStateMap.Add(NowUIAProperty.NOW_PROP_IS_CHECKED, "on");
            m_nameStateMap.Add(NowUIAProperty.NOW_PROP_IS_UNCHECKED, "off");
        }

        /// <summary>
        /// Get signature of UI Automation element
        /// </summary>
        /// <param name="runtimeElement">Automation Element</param>
        /// <returns>the signature</returns>
        public String GetSignature(AutomationElement runtimeElement)
        {
            return String.Format("{0}", runtimeElement.GetHashCode());
        }

        /// <summary>
        /// Get UI Automation Property
        /// </summary>
        /// <param name="runtimeElement">Automation Element</param>
        /// <param name="strPropName">name of Property</param>
        /// <returns>the value</returns>
        public String GetUIProperty(AutomationElement runtimeElement, String strPropName)
        {
            String strResult = String.Empty;
            if (runtimeElement != null)
            {
                if (m_propMap.ContainsKey(strPropName))
                {
                    try
                    {
                        Object objValue = runtimeElement.GetCurrentPropertyValue(m_propMap[strPropName] as AutomationProperty);
                        if (objValue != null)
                        {
                            strResult = objValue.ToString();
                        }
                    }
                    catch (System.Exception ex)
                    {
                        NowUIALogger.GetInstance().LogError("[NowUIAService.GetUIProperty]", ex.Message);
                        return String.Empty;
                    }
                }
            }

            return strResult;
        }

        public int GetStatus(AutomationElement runtimeElement, ref int nResult)
        {
            nResult = NowUIADefine.NOW_OK;
            int nState = 0;
            bool check = false;
            try
            {
                foreach (KeyValuePair<String, int> itemState in m_stateValMap)
                {
                    check = (bool)runtimeElement.GetCurrentPropertyValue(m_checkUIHaveStateMap[itemState.Key] as AutomationProperty);
                    if (check)
                    {
                        String strState = "";
                        strState = runtimeElement.GetCurrentPropertyValue(m_propMap[itemState.Key] as AutomationProperty).ToString();
                        if (strState.ToLower().Equals(m_nameStateMap[itemState.Key]))
                        {
                            if (m_nameStateMap.ContainsKey(itemState.Key))
                            {
                                if (strState.ToLower().Equals(m_nameStateMap[itemState.Key]))
                                {
                                    nState = nState | itemState.Value;
                                }
                            }
                        }
                    }
                }
            }
            catch (System.Exception )
            {
                nResult = NowUIADefine.NOW_FALSE;
            }
            
            return nState;
        }

        public PropertyCondition GetCondition(String strPropValue)
        {
            PropertyCondition condResult = null;

            String propName = "";
            String propValue = "";
            String[] arrTemp = null;
            String[] arrPropValue = strPropValue.Split(new char[] { '|' });
            foreach (String prop in arrPropValue)
            {
                arrTemp = prop.Split(new char[] { '=' });
                if (arrTemp.Length == 2)
                {
                    propName = arrTemp[0];
                    propValue = arrTemp[1];

                    condResult = new PropertyCondition(m_propMap[propName] as AutomationProperty, propValue);
                }
            }

            return condResult;
        }
    }
}

    

