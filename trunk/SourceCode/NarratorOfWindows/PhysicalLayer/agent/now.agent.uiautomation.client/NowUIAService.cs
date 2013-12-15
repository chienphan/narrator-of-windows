using System.Windows.Automation;
using System.Windows;
using System;
using System.Collections.Generic;

namespace now.agent.uiautomation.client
{
    public class NowUIAService
    {
        private static NowUIAService m_instance = null;

        private NowUIAService()
        {

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

        public String GetSignature(AutomationElement currentElement)
        {
            return String.Format("{0}", currentElement.GetHashCode());
        }
    }
}
