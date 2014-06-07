using System;
using System.Collections.Generic;
using now.agent.uiautomation.client.logger;

namespace now.agent.uiautomation.client.argument
{
    class NowUIAArgumentIn
    {
        private static NowUIAArgumentIn m_nstance = null;
        private String m_actionName;
        private Dictionary<String, Object> m_arguments;
        
        public String ActionName { 
            get { return m_actionName; }
            set { m_actionName = value; }
        }
        
        NowUIAArgumentIn()
        {
            m_arguments = new Dictionary<String, Object>();
        }

        public static NowUIAArgumentIn GetInstance()
        {
            if (m_nstance == null)
            {
                m_nstance = new NowUIAArgumentIn();
            }
            return m_nstance;
        }

        public void AddArgument(String argumentName, Object argumentValue)
        {
            if (!m_arguments.ContainsKey(argumentName))
            {
                m_arguments.Add(argumentName, argumentValue);
            }
        }

        public int GetIntArgument(String argumentName)
        {
            int nResult = -1;
            try
            {
                if (m_arguments.ContainsKey(argumentName))
                {
                    Object argumentValue;
                    bool isSuccess = m_arguments.TryGetValue(argumentName, out argumentValue);
                    if (isSuccess)
                    {
                        nResult = (int)argumentValue;
                    }
                }
            }
            catch (Exception ex)
            {
                NowUIALogger.GetInstance().LogError(String.Format("[NowUIAArgumentIn.GetIntArgument]{0}", ex.Message));
            }
            return nResult;
        }

        public String GetStringArgument(String argumentName)
        {
            String sResult = String.Empty;
            try
            {
                if (m_arguments.ContainsKey(argumentName))
                {
                    Object argumentValue;
                    bool isSuccess = m_arguments.TryGetValue(argumentName, out argumentValue);
                    if (isSuccess)
                    {
                        sResult = argumentValue as String;
                    }
                }
            }
            catch (System.Exception ex)
            {
                NowUIALogger.GetInstance().LogError(String.Format("[NowUIAArgumentIn.GetStringArgument]{0}", ex.Message));
            }
            return sResult;
        }

        public bool GetBooleanArgument(String argumentName)
        {
            bool bResult = false;
            try
            {
                if (m_arguments.ContainsKey(argumentName))
                {
                    Object argumentValue;
                    bool isSuccess = m_arguments.TryGetValue(argumentName, out argumentValue);
                    if (isSuccess)
                    {
                        bResult = (bool) argumentValue;
                    }
                }
            }
            catch (System.Exception ex)
            {
                NowUIALogger.GetInstance().LogError(String.Format("[NowUIAArgumentIn.GetBooleanArgument]{0}", ex.Message));
            }
            return bResult;
        }

        public void ClearArguments()
        {
            if (m_arguments != null)
            {
                m_arguments.Clear();
            }
        }
    }
}
