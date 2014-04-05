using System;
using System.Windows;
using System.Windows.Automation;
using System.Collections.Generic;
using System.Text.RegularExpressions;

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
                    //TODO: Need check for control type and decide the control to return
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

        public int GetUIState(String strSignatureControl, ref int stateValue)
        {
            //NowOutPut.OutputDebugString(strSignatureControl);
            int nResult = NowUIADefine.NOW_FALSE;
            AutomationElement runtimeElement = NowUIAStorage.GetInstance().GetUIObjectFormCache(strSignatureControl);
            if (runtimeElement != null)
            {
              //  NowOutPut.OutputDebugString("ok");
                stateValue = NowUIAService.GetInstance().GetUIState(runtimeElement, ref nResult);
               // NowOutPut.OutputDebugString(stateValue.ToString());
            }
            else
            {
               // NowOutPut.OutputDebugString("not ok");
            }
            return nResult;
        }


        public int GetWindowByTitle(String strTitleWindow, ref String strHandleWindow)
        {
            NowUIALogger.GetInstance().LogInfor("[GetWindowByTitle]" + strTitleWindow);
            int nResult = NowUIADefine.NOW_FALSE;
            AutomationElement currentWindow = null;
            
            //check for regular expression
            if (NowUIAUtilities.GetInstance().IsRegExpPattern(strTitleWindow))
            {
                strTitleWindow = NowUIAUtilities.GetInstance().TrimRegExpPattern(strTitleWindow);
            }

            //get all windows
            List<AutomationElement> listWindow = new List<AutomationElement>();
            TreeWalker rawView = TreeWalker.RawViewWalker;
            currentWindow = rawView.GetFirstChild(AutomationElement.RootElement);

            while (currentWindow != null)
            {
                NowUIALogger.GetInstance().LogInfor(">>>" + currentWindow.Current.Name);
                listWindow.Add(currentWindow);
                currentWindow = rawView.GetNextSibling(currentWindow);
            }

            //find the window has strTitleWindow
            foreach (AutomationElement window in listWindow)
            {
                if (Regex.IsMatch(window.Current.Name, strTitleWindow))
                {
                    NowUIALogger.GetInstance().LogInfor("IsMatch:" + window.Current.Name + "|" + window.Current.NativeWindowHandle);
                    currentWindow = window;
                    nResult = NowUIADefine.NOW_OK;
                    break;
                }
            }

            if (nResult == NowUIADefine.NOW_OK)
            {
                //keep the window element to cache and return strHandleWindow
                strHandleWindow = String.Format("{0}", currentWindow.Current.NativeWindowHandle);
                NowUIAStorage.GetInstance().AddToCache(strHandleWindow, currentWindow);
            }

            return nResult;
        }

        public int GetControlByCondition(String strWindowHandle, String strPropsData, ref String strSignatureControl, ref String strControlType)
        {
            NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] handle: " + strWindowHandle);
            int nResult = NowUIADefine.NOW_FALSE;
            AutomationElement window = NowUIAStorage.GetInstance().GetUIObjectFormCache(strWindowHandle);
            if (window != null)
            {
                NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] window: " + window.Current.Name);
                Condition condControl = NowUIAService.GetInstance().GetCondition(strPropsData);
                if (condControl != null)
                {
                    AutomationElement control = window.FindFirst(TreeScope.Descendants, condControl);
                    if (control != null)
                    {
                        NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] control: " + control.Current.Name);
                        strSignatureControl = NowUIAService.GetInstance().GetSignature(control);
                        strControlType = control.Current.LocalizedControlType;
                        NowUIAStorage.GetInstance().AddToCache(strSignatureControl, control);

                        nResult = NowUIADefine.NOW_OK;
                    }
                    else
                    {
                        NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] control: NULL");
                    }
                }
            }
            else
            {
                NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] window: NULL");
            }
            return nResult;
        }
    }
}
