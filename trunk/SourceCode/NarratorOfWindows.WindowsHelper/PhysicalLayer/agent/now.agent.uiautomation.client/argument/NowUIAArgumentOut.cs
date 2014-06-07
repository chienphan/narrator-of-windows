using System;
using now.agent.uiautomation.client.logger;

namespace now.agent.uiautomation.client.argument
{
    class NowUIAArgumentOut
    {
        private static NowUIAArgumentOut m_instance = null;
        private Object m_data;
        public Object Data { set{ m_data = value; } }

        NowUIAArgumentOut()
        {
        }

        public static NowUIAArgumentOut GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIAArgumentOut();
            }
            return m_instance;
        }

        public int GetIntArgument()
        {
            int nResult = -1;
            try
            {
                if (m_data != null)
                {
                    nResult = (int)m_data;
                }
            }
            catch (System.Exception ex)
            {
                NowUIALogger.GetInstance().LogError(String.Format("[NowUIAArgumentOut.GetIntArgument]{0}", ex.Message));
            }
            
            return nResult;
        }

        public String GetStringArgument()
        {
            String sResult = String.Empty;
            try
            {
                if (m_data != null)
                {
                    sResult = m_data as String;
                }
            }
            catch (System.Exception ex)
            {
                NowUIALogger.GetInstance().LogError(String.Format("[NowUIAArgumentOut.GetStringArgument]{0}", ex.Message));
            }

            return sResult;
        }

        public bool GetBooleanArgument()
        {
            bool bResult = false;
            try
            {
                if (m_data != null)
                {
                    bResult = (bool) m_data;
                }
            }
            catch (System.Exception ex)
            {
                NowUIALogger.GetInstance().LogError(String.Format("[NowUIAArgumentOut.GetBooleanArgument]{0}", ex.Message));
            }

            return bResult;
        }

        public void ClearArgumanet()
        {
            m_data = null;
        }
    }
}
