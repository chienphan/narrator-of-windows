using System.Windows.Automation;
using System.Windows;
using System;

namespace now.agent.uiautomation.client
{
    public class NowAutomationService
    {
        private static NowAutomationService m_instance = null;

        private NowAutomationService()
        {

        }

        /// <summary>
        /// Get Singleton instance of NowAutomationService
        /// </summary>
        /// <returns>NowAutomationService instance</returns>
        public static NowAutomationService GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowAutomationService();
            }
            return m_instance;
        }

        /// <summary>
        /// Get UI Automation element at point
        /// </summary>
        /// <param name="point">point of mouse</param>
        /// <returns>Return AutomationElement if succeed, null if false</returns>
        public AutomationElement GetElementAtPoint(Point point)
        {
            AutomationElement returnElement = null;

            try
            {
                returnElement = AutomationElement.FromPoint(point);
            }
            catch (System.Exception ex)
            {
                System.Diagnostics.Debug.WriteLine(String.Format("[NowAutomationElement][GetElementAtPoint] Exception[{0}]", ex.Message));
            }

            return returnElement;
        }
    }
}
