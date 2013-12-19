using System;
using System.Collections.Generic;
using System.Windows.Automation;

namespace now.agent.uiautomation.client
{
    public class NowUIAService
    {
        private static NowUIAService m_instance = null;
        private static Dictionary<String, Object> m_propMap = null;

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
        }

        public String GetSignature(AutomationElement runtimeElement)
        {
            return String.Format("{0}", runtimeElement.GetHashCode());
        }

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
                            NowUIALogger.GetInstance().LogError("[NowUIAService][GetUIProperty] [{0}]", strResult);
                        }
                    }
                    catch (System.Exception ex)
                    {
                        return String.Empty;
                    }
                }
            }

            return strResult;
        }
    }
}
