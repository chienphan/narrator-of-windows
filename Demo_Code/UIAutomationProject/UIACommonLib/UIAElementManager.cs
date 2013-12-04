using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Automation;

namespace UIACommonLib
{
    public class UIAElementManager
    {
        private static UIAElementManager m_instance;
        private UIAElementManager()
        {
        }

        public static UIAElementManager GetInstance()
        {
            if (m_instance != null)
            {
                m_instance = new UIAElementManager();
            }
            return m_instance;
        }

        public string GetAllTopWindows()
        {
            string strResult = "";
            AutomationElementCollection listTopWindows = AutomationElement.RootElement.FindAll(TreeScope.Children, Condition.TrueCondition);
            foreach (AutomationElement window in listTopWindows)
            {
                strResult += window.Current.NativeWindowHandle + "|";
            }
            return strResult;
        }
    }
}
