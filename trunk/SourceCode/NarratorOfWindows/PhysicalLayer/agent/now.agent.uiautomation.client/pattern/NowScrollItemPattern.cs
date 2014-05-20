using System;
using System.Windows.Automation;
using now.agent.uiautomation.client.constant;

namespace now.agent.uiautomation.client.pattern
{
    class NowScrollItemPattern
    {
        private static NowScrollItemPattern m_intance = null;
        private NowScrollItemPattern() { }

        public static NowScrollItemPattern GetInstance()
        {
            if (m_intance == null)
            {
                m_intance = new NowScrollItemPattern();
            }
            return m_intance;
        }

        public bool IsScrollItemPatternAvailable(AutomationElement element)
        {
            bool bResult = false;
            if (element != null)
            {
                bResult = (bool)element.GetCurrentPropertyValue(AutomationElement.IsScrollItemPatternAvailableProperty);
            }
            return bResult;
        }

        public int ScrollIntoView(AutomationElement element)
        {
            int nResult = NowUIADefine.NOW_FALSE;
            if (element != null)
            {
                if (IsScrollItemPatternAvailable(element) == true)
                {
                    Object obj = element.GetCurrentPattern(ScrollItemPattern.Pattern);
                    if (obj != null)
                    {
                        ScrollItemPattern scrollItemPattern = obj as ScrollItemPattern;
                        scrollItemPattern.ScrollIntoView();
                        nResult = NowUIADefine.NOW_OK;
                    }
                }
            }
            return nResult;
        }
    }
}
