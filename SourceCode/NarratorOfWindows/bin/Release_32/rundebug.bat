REM Copy all jar libraries into debug directory...
set JAVA_BUILD_DIRECTORY=F:\My_Data\narrator-of-windows\SourceCode\NarratorOfWindows\ProductLayer\now.window.lib\dist
set DEBUG_DIRECTORY=F:\My_Data\narrator-of-windows\SourceCode\NarratorOfWindows\bin\Release_32
if exist %JAVA_BUILD_DIRECTORY% xcopy %JAVA_BUILD_DIRECTORY% %DEBUG_DIRECTORY% /E /Y

REM Call jar entry point...
F:\My_Data\narrator-of-windows\SourceCode\NarratorOfWindows\jre\jre-7u45-windows-i586\jre1.7.0_45\bin\java.exe -jar "now.window.lib.jar"

pause