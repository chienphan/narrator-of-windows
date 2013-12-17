using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Automation;

namespace now.agent.uiautomation.client
{
    class NowUIAStorage
    {
        private static NowUIAStorage m_instance = null;

        private Dictionary<String, AutomationElement> m_dictionary = null;

        private NowUIAStorage()
        {

        }

        /// <summary>
        /// Get Singleton instance of NowAutomationService
        /// </summary>
        /// <returns>NowAutomationService instance</returns>
        public static NowUIAStorage GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIAStorage();
            }
            return m_instance;
        }

        public void AddToCache(String strSignature, AutomationElement currentElement)
        {
            //int nResult = NowUIADefine.NOW_FALSE;
            if (m_dictionary == null)
            {
                m_dictionary = new Dictionary<String, AutomationElement>();
            }

            if (m_dictionary.Count > 0)
            {
                m_dictionary.Clear();
            }

            m_dictionary.Add(strSignature, currentElement);
        }

        public void ClearCache()
        {
            if (m_dictionary != null)
            {
                m_dictionary.Clear();
            }
        }

        public AutomationElement GetUIObjectFormCache(String strSignature)
        {
            AutomationElement returnElement = null;
            if (m_dictionary.TryGetValue(strSignature,out returnElement))
            {
                return returnElement;
            }
            return null;
        }
    }
}
