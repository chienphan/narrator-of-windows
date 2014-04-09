using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Automation;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.logger;
using now.agent.uiautomation.client.storage;
using now.agent.uiautomation.client.utility;
using now.agent.uiautomation.client.argument;
using now.agent.uiautomation.client.action;

namespace now.agent.uiautomation.client.communication
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
        //public int GetElementAtPoint(Point point, ref String strSignatureControl, ref String strControlType)
        //{
        //    int nResult = NowUIADefine.NOW_FALSE;
        //    AutomationElement currentElement = null;

        //    try
        //    {
        //        //Get element at point
        //        currentElement = AutomationElement.FromPoint(point);
        //        if (currentElement != null)
        //        {
        //            //TODO: Need check for control type and decide the control to return
        //            // Get signature, control type and create cache
        //            strControlType = currentElement.Current.LocalizedControlType; //TODO: Need check for get LocalizedControlType or ControlType
        //            strSignatureControl = NowUIAService.GetInstance().GetSignature(currentElement);
        //            NowUIAStorageAction.GetInstance().AddToCache(strSignatureControl, currentElement);

        //            nResult = NowUIADefine.NOW_OK;
        //        }
        //    }
        //    catch (System.Exception ex)
        //    {
        //        NowUIALogger.GetInstance().LogError("[NowUIACommunication][GetElementAtPoint] Exception [{0}]", ex.Message);
        //    }

        //    return nResult;
        //}
        
        /// <summary>
        /// Get UI Automation Property
        /// </summary>
        /// <param name="strSignatureControl">signature of Automation Element</param>
        /// <param name="strPropName">Name of property</param>
        /// <param name="strValue">return value</param>
        /// <returns>NOW_OK if succeed, NOW_FALSE if false</returns>
        //public int GetUIProperty(String strSignatureControl, String strPropName, ref String strValue)
        //{
        //    int nResult = NowUIADefine.NOW_FALSE;
        //   // NowUIALogger.GetInstance().LogInfor("ok check commu {0}",1);
        //    AutomationElement runtimeElement = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strSignatureControl);
        //    if (runtimeElement != null)
        //    {
        //        strValue = NowUIAService.GetInstance().GetUIProperty(runtimeElement, strPropName);
        //        //if (!strValue.Equals(String.Empty))
        //        //{
        //            nResult = NowUIADefine.NOW_OK;
        //        //}
        //       // NowOutPut.OutputDebugString(nResult.ToString());
        //    }
        // //   NowOutPut.OutputDebugString(nResult.ToString());
        //    return nResult;
        //}

        //public int GetUIState(String strSignatureControl, ref int stateValue)
        //{
        //    //NowOutPut.OutputDebugString(strSignatureControl);
        //    int nResult = NowUIADefine.NOW_FALSE;
        //    AutomationElement runtimeElement = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strSignatureControl);
        //    if (runtimeElement != null)
        //    {
        //      //  NowOutPut.OutputDebugString("ok");
        //        stateValue = NowUIAService.GetInstance().GetStatus(runtimeElement, ref nResult);
        //       // NowOutPut.OutputDebugString(stateValue.ToString());
        //    }
        //    else
        //    {
        //       // NowOutPut.OutputDebugString("not ok");
        //    }
        //    return nResult;
        //}
        
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
                //NowUIALogger.GetInstance().LogInfor(">>>" + currentWindow.Current.Name);
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
                NowUIAStorageAction.GetInstance().AddToCache(strHandleWindow, currentWindow);
            }

            return nResult;
        }

        public int GetControlByCondition(String strWindowHandle, String strPropsData, ref String strSignatureControl, ref String strControlType)
        {
            NowUIALogger.GetInstance().LogInfor("[GetControlByCondition] handle: " + strWindowHandle);
            int nResult = NowUIADefine.NOW_FALSE;
            AutomationElement window = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strWindowHandle);
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
                        NowUIAStorageAction.GetInstance().AddToCache(strSignatureControl, control);

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

        public int BringWindowToTop(String strWindowSignature)
        {
            NowUIALogger.GetInstance().LogInfor("[BringWindowToTop]" + strWindowSignature);
            int nResult = NowUIADefine.NOW_FALSE;
            
            AutomationElement window = NowUIAStorageAction.GetInstance().GetUIObjectFormCache(strWindowSignature.Trim());
            NowUIALogger.GetInstance().LogInfor("[BringWindowToTop] GetUIObjectFormCache");
            if (window != null)
            {
                NowUIALogger.GetInstance().LogInfor("[BringWindowToTop] window: not NULL");
                object obj = window.GetCurrentPropertyValue(AutomationElement.IsWindowPatternAvailableProperty);
                if (obj != null)
                {
                    bool hasWindowPattern = (bool)obj;
                    if (hasWindowPattern == true)
                    {
                        NowUIALogger.GetInstance().LogInfor("[BringWindowToTop] hasWindowPattern");
                        obj = window.GetCurrentPattern(WindowPattern.Pattern);
                        if (obj != null)
                        {
                            WindowPattern windowPattern = obj as WindowPattern;
                            windowPattern.SetWindowVisualState(WindowVisualState.Normal);
                            nResult = NowUIADefine.NOW_OK;
                        }
                    }
                }
            }
            return nResult;
        }

        /// <summary>
        /// Divert to Action and call it
        /// </summary>
        /// <param name="argumentIn"></param>
        /// <param name="argumentOut"></param>
        /// <returns></returns>
        //public int DoAction(NowUIAArgumentIn argumentIn, ref NowUIAArgumentOut argumentOut)
        //{
        //    int nResult = NowUIADefine.NOW_FALSE;

        //    if (argumentIn != null && argumentOut != null)
        //    {
        //        try
        //        {
        //            nResult = NowUIAActionManager.GetInstance().GetAction(argumentIn.ActionName).DoAction();
        //        }
        //        catch (Exception ex)
        //        {
        //            NowUIALogger.GetInstance().LogWarning("[NowUIACommunication.DoAction] {0}", ex.Message);
        //        }
        //    }
        //    else
        //    {
        //        NowUIALogger.GetInstance().LogWarning("[NowUIACommunication.DoAction] argument null!");
        //    }
        //    return nResult;
        //}
    }
}
