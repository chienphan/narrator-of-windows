using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;

namespace now.agent.uiautomation.client
{
    public class NowUIALogger
    {
        

        private delegate void DelegateLogger(String log);

        private static NowUIALogger m_instance = null;
        private static String m_logConfigFileName = "\\logconfig.txt";

        private int m_logMode = NowLogMode.LOG_NONE;
        private Trace m_objTrace = null;

        private String m_logFileFullPath = "";

        //private Dictionary<int, DelegateLogger> m_delegateLoggerMethod = null;

        private NowUIALogger()
        {
            InitLogConfig();
            //InitTraceInstance();
        }

        /// <summary>
        /// Check environment and config file to log or not. If log, initial information form log file config
        /// </summary>
        private void InitLogConfig()
        {
            String strLogMode = NowUIAUtilities.GetInstance().GetEnvironmentVariableValue(NowUIAEnvironmentVariable.NOW_DEBUG_MODE);
            if (strLogMode == String.Empty && strLogMode.Equals(NowEnvVariable.ENV_VARIABLE_LOG_DISABLE))
            {
                m_logMode = NowLogMode.LOG_NONE;
            }
            if (strLogMode.Equals(NowEnvVariable.ENV_VARIABLE_LOG_ENABLE))
            {
                NowOutPut.OutputDebugString("[InitLogConfig] ENV_VARIABLE_LOG_ENABLE");
                InitLogFile();
                InitTraceInstance();
            }        
        }

        /// <summary>
        /// Init log mode and log file (if log mode = file). Make sure environment variable log mode is 1
        /// </summary>
        /// <returns></returns>
        private void InitLogFile()
        {
            NowOutPut.OutputDebugString("[InitLogFile] BEGIN");
            m_logMode = NowLogMode.LOG_NONE;
            String strLogConfigFilePath = String.Empty;

            //Get and check environment variable NOW_DEBUG_MODE 
            if (NowUIAUtilities.GetInstance().GetEnvironmentVariableValue(NowUIAEnvironmentVariable.NOW_DEBUG_MODE).Equals(NowEnvVariable.ENV_VARIABLE_LOG_ENABLE))
            {
                ////Get and check environment variable NOW_DEBUG_DIRECTORY
                String strDebugDirectory = NowUIAUtilities.GetInstance().GetEnvironmentVariableValue(NowUIAEnvironmentVariable.NOW_DEBUG_DIRECTORY);
                if (!strDebugDirectory.Equals(String.Empty))
                {
                    strLogConfigFilePath = strDebugDirectory + m_logConfigFileName;
                    
                    String line = String.Empty;
                    // Read the file and display it line by line.
                    StreamReader file = new StreamReader(strLogConfigFilePath);
                    if((line = file.ReadLine()) != null)
                    {
                        //Check log mode
                        if (line.Split('=')[0].ToLower().Equals("mode") && line.Split('=')[1].ToLower().Equals("debugview"))
                        {
                            m_logMode = NowLogMode.LOG_DEBUG_VIEW;
                        }//end-if
                        if (line.Split('=')[0].ToLower().Equals("mode") && line.Split('=')[1].ToLower().Equals("file"))
                        {
                            //Check and get log dir
                            if ((line = file.ReadLine()) != null)
                            {
                                if (line.Split('=')[0].ToLower().Equals("logdir"))
                                {
                                    String strLogFileName = NowUIAUtilities.GetInstance().GetProcessId() + "-" + NowUIAUtilities.GetInstance().GetCurrentDateTime() + ".txt";
                                    m_logMode = NowLogMode.LOG_FILE;
                                    m_logFileFullPath = line.Split('=')[1];
                                    m_logFileFullPath += "\\UIA_Agent\\";// +strLogFileName;
                                    if (NowUIAUtilities.GetInstance().CreateDirectory(m_logFileFullPath))
                                    {
                                        m_logFileFullPath += strLogFileName;
                                    }
                                    else
                                    {
                                        m_logMode = NowLogMode.LOG_NONE;
                                    }
                                    NowOutPut.OutputDebugString(m_logFileFullPath);
                                }
                            }
                        }//end-if
                    }//end-if
                    file.Close();
                }//end-if
            }//end-if
            NowOutPut.OutputDebugString("[InitLogFile] END");
        }//end-method

        /// <summary>
        /// init trace instance
        /// </summary>
        private void InitTraceInstance()
        {
            NowOutPut.OutputDebugString("[InitTraceInstance] BEGIN");
            if (Trace.Listeners.Count > 0)
            {
                Trace.Listeners.Clear();
            }
            if (m_logMode == NowLogMode.LOG_DEBUG_VIEW)
            {
                Trace.Listeners.Add(new DefaultTraceListener());
            }
            if (m_logMode == NowLogMode.LOG_FILE)
            {
                Trace.Listeners.Add(new TextWriterTraceListener(m_logFileFullPath));
                Trace.AutoFlush = true;
            }
            NowOutPut.OutputDebugString("[InitTraceInstance] END");
        }//end-method

        public static NowUIALogger GetInstance()
        {
            if (m_instance == null)
            {
                m_instance = new NowUIALogger();
            }
            return m_instance;
        }
        
        public void LogInfor(String format, params object[] args)
        {
            Trace.TraceInformation(format, args);
        }

        public void LogError(String format, params object[] args)
        {
            Trace.TraceError(format, args);
        }

        public void LogWarning(String format, params object[] args)
        {
            Trace.TraceWarning(format, args);
        }
    }

    public class NowOutPut
    {
        [DllImport("kernel32.dll")]
        public static extern void OutputDebugString(string strOutPut);
    }
}
