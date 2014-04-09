using System;
using System.Collections.Generic;
using now.agent.uiautomation.client.interfaces;
using now.agent.uiautomation.client.constant;
using now.agent.uiautomation.client.action.common;
using now.agent.uiautomation.client.logger;
using now.agent.uiautomation.client.argument;

namespace now.agent.uiautomation.client.action
{
    class NowUIAActionManager
    {
        private static NowUIAActionManager m_instance = null;
        private Dictionary<String, INowUIAAction> m_mapAction = null;
        private NowUIAActionManager() 
        {
            InitializeActionMap();
        }

        private void InitializeActionMap()
        {
            m_mapAction = new Dictionary<String, INowUIAAction>();
            m_mapAction.Add(NowUIAActionConst.NOW_GET_PROPERTY, new GetProperty());
            m_mapAction.Add(NowUIAActionConst.UIA_ACTION_GET_ELEMENT_AT_POINT, new GetElementAtPoint());
            m_mapAction.Add(NowUIAActionConst.UIA_ACTION_GETSTATUS, new GetStatus());
        }

        public static NowUIAActionManager GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIAActionManager();
            }
            return m_instance;
        }

        public int DoAction()
        {
            int nResult = NowUIADefine.NOW_FALSE;
            INowUIAAction actionInstance;
            try
            {
                //Empty OUT argument.
                NowUIAArgumentOut.GetInstance().ClearArgumanet();

                //Get action by name
                String actionName = NowUIAArgumentIn.GetInstance().ActionName;
                bool isSuccess = m_mapAction.TryGetValue(actionName, out actionInstance);

                //Do action
                if (isSuccess)
                {
                    nResult = actionInstance.DoAction();
                }
                else
                {
                    NowUIALogger.GetInstance().LogWarning("[NowUIAActionManager.GetAction] not succeed");
                }
            }
            catch (System.Exception ex)
            {
                NowUIALogger.GetInstance().LogError("[NowUIAActionManager.GetAction]{0}", ex.Message);
            }

            return nResult;
        }
    }
}
