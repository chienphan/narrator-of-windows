set PROJECT_DIR=F:\UIAutomation\narrator-of-windows\SourceCode\NarratorOfWindows\PhysicalLayer\agent\now.agent.uiautomation.client
set OUT_DIR=F:\UIAutomation\narrator-of-windows\SourceCode\NarratorOfWindows\bin\Debug_32
set NET_REFERENCE_DIR=C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\.NETFramework\v4.0
set NET_FRAMEWORK_DIR=C:\Windows\Microsoft.NET\Framework\v4.0.30319

"%NET_FRAMEWORK_DIR%\csc.exe" /debug /target:module /define:TRACE /reference:"%NET_REFERENCE_DIR%\UIAutomationClient.dll" /reference:"%NET_REFERENCE_DIR%\UIAutomationTypes.dll" /reference:"%NET_REFERENCE_DIR%\WindowsBase.dll" /out:%OUT_DIR%\now.agent.uiautomation.client.dll %PROJECT_DIR%\*.cs %PROJECT_DIR%\utility\*.cs %PROJECT_DIR%\storage\*.cs %PROJECT_DIR%\logger\*.cs %PROJECT_DIR%\interfaces\*.cs %PROJECT_DIR%\constant\*.cs %PROJECT_DIR%\communication\*.cs %PROJECT_DIR%\action\*.cs %PROJECT_DIR%\action\common\*.cs %PROJECT_DIR%\argument\*.cs