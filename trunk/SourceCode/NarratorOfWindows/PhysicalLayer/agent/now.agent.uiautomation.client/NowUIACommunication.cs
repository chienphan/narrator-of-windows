using System;
using System.Windows;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Automation;

namespace now.agent.uiautomation.client
{
    public class NowUIACommunication
    {
        private static NowUIACommunication m_instance = null;

        private NowUIACommunication()
        {

        }

        /// <summary>
        /// Get Singleton instance of NowAutomationService
        /// </summary>
        /// <returns>NowAutomationService instance</returns>
        public static NowUIACommunication GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIACommunication();
            }
            return m_instance;
        }

        /// <summary>
        /// Get UI Automation element at point
        /// </summary>
        /// <param name="point">point of mouse</param>
        /// <returns>Return AutomationElement if succeed, null if false</returns>
        public int GetElementAtPoint(Point point, ref String strSignatureControl, ref String strControlType)
        {
            int nResult = NowUIADefine.NOW_FALSE;
            AutomationElement currentElement = null;

            try
            {
                //Get element at point
                currentElement = AutomationElement.FromPoint(point);
                if (currentElement != null)
                {
                    // Get signature, control type and create cache
                    strControlType = currentElement.Current.LocalizedControlType; //TODO: Need check for get LocalizedControlType or ControlType
                    strSignatureControl = NowUIAService.GetInstance().GetSignature(currentElement);
                    NowUIAStorage.GetInstance().AddToCache(strSignatureControl, currentElement);

                    nResult = NowUIADefine.NOW_OK;
                }
            }
            catch (System.Exception ex)
            {
                System.Diagnostics.Debug.WriteLine(String.Format("[NowAutomationElement][GetElementAtPoint] Exception[{0}]", ex.Message));
            }

            return nResult;
        }

        
        //public int GetHelpTextProperty(String strSignatureControl, ref String strHelpText)
        //{
        //    int nResult = NowUIADefine.NOW_FALSE;
            
        //    AutomationElement runtimeElement = NowUIAStorage.GetInstance().GetUIObjectFormCache(strSignatureControl);
        //    if (runtimeElement != null)
        //    {
        //        strHelpText = runtimeElement.Current.HelpText;
        //        nResult = NowUIADefine.NOW_OK;
        //    }

        //    return nResult;
        //}

        public int GetUIProperty(String strSignatureControl, String strPropName, ref String strValue)
        {
            int nResult = NowUIADefine.NOW_FALSE;

            AutomationElement runtimeElement = NowUIAStorage.GetInstance().GetUIObjectFormCache(strSignatureControl);
            if (runtimeElement != null)
            {
                strValue = NowUIAService.GetInstance().GetUIProperty(runtimeElement, strPropName);
                nResult = NowUIADefine.NOW_OK;
            }

            return nResult;
        }
    }
}
