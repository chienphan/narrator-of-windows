using System;
using System.Collections.Generic;
using System.Windows.Automation;
using now.agent.uiautomation.client.logger;

namespace now.agent.uiautomation.client.storage
{
    class NowUIAStorageAction
    {
        private static NowUIAStorageAction m_instance = null;

        private Dictionary<String, AutomationElement> m_dictionary = null;

        private NowUIAStorageAction()
        {
            m_dictionary = new Dictionary<String, AutomationElement>();
        }

        public static NowUIAStorageAction GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIAStorageAction();
            }
            return m_instance;
        }

        public void AddToCache(String strSignature, AutomationElement currentElement)
        {
            if (!m_dictionary.ContainsKey(strSignature))
            {
                m_dictionary.Add(strSignature, currentElement);
            }
        }

        public AutomationElement GetUIObjectFormCache(String strSignature)
        {
            //AutomationElement returnElement = NowUIAStorage.GetInstance().GetUIObjectFormCache(strSignature);
            //if (returnElement == null)
            //{
            //    m_dictionary.TryGetValue(strSignature, out returnElement);
            //}
            AutomationElement returnElement = null;
            m_dictionary.TryGetValue(strSignature, out returnElement);
            return returnElement;
        }

        public void ClearCache()
        {
            if (m_dictionary != null)
            {
                m_dictionary.Clear();
            }
        }
    }
}
