using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Automation;
using now.agent.uiautomation.client.constant;

namespace now.agent.uiautomation.client.pattern
{
    class NowValuePattern
    {
        private static NowValuePattern m_intance = null;
        private NowValuePattern() { }

        public static NowValuePattern GetInstance()
        {
            if (m_intance == null)
            {
                m_intance = new NowValuePattern();
            }
            return m_intance;
        }

        public bool IsValuePatternAvailable(AutomationElement element)
        {
            bool bResult = false;
            if (element != null)
            {
                bResult = (bool)element.GetCurrentPropertyValue(AutomationElement.IsValuePatternAvailableProperty);
            }
            return bResult;
        }

        public int SetValue(AutomationElement element, String value)
        {
            int nResult = NowUIADefine.NOW_FALSE;
            if (element != null)
            {
                if (IsValuePatternAvailable(element) == true)
                {
                    Object obj = element.GetCurrentPattern(ValuePattern.Pattern);
                    if (obj != null)
                    {
                        ValuePattern valuePattern = obj as ValuePattern;
                        valuePattern.SetValue(value);
                        if (valuePattern.Current.Value.Equals(value))
                        {
                            nResult = NowUIADefine.NOW_OK;
                        }
                    }
                }
            }
            return nResult;
        }
    }
}
