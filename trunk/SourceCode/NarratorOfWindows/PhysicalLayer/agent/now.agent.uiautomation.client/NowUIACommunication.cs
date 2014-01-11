using System;
using System.Windows;
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
                NowUIALogger.GetInstance().LogError("[NowUIACommunication][GetElementAtPoint] Exception [{0}]", ex.Message);
            }

            return nResult;
        }
        
        /// <summary>
        /// Get UI Automation Property
        /// </summary>
        /// <param name="strSignatureControl">signature of Automation Element</param>
        /// <param name="strPropName">Name of property</param>
        /// <param name="strValue">return value</param>
        /// <returns>NOW_OK if succeed, NOW_FALSE if false</returns>
        public int GetUIProperty(String strSignatureControl, String strPropName, ref String strValue)
        {
            int nResult = NowUIADefine.NOW_FALSE;
           // NowUIALogger.GetInstance().LogInfor("ok check commu {0}",1);
            AutomationElement runtimeElement = NowUIAStorage.GetInstance().GetUIObjectFormCache(strSignatureControl);
            if (runtimeElement != null)
            {
                strValue = NowUIAService.GetInstance().GetUIProperty(runtimeElement, strPropName);
                //if (!strValue.Equals(String.Empty))
                //{
                    nResult = NowUIADefine.NOW_OK;
                //}
               // NowOutPut.OutputDebugString(nResult.ToString());
            }
         //   NowOutPut.OutputDebugString(nResult.ToString());
            return nResult;
        }


        public int GetUIState(String strSignatureControl, String strStateName, ref int stateValue)
        {
            
           // NowOutPut.OutputDebugString(strStateName);
           int nResult = NowUIADefine.NOW_FALSE;

            AutomationElement runtimeElement = NowUIAStorage.GetInstance().GetUIObjectFormCache(strSignatureControl);
            if (runtimeElement != null)
            {
                stateValue = NowUIAService.GetInstance().GetUIState(runtimeElement, strStateName, ref nResult);
               // NowOutPut.OutputDebugString(stateValue.ToString());
            }
            return nResult;
        }
    }
}
