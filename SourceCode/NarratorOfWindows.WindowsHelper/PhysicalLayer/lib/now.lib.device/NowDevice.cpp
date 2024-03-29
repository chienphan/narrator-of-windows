#include "NowDevice.h"
#include "NowStringProcessor_UIA.h"

NowDevice::NowDevice(void)
{
}

NowDevice::~NowDevice(void)
{
}

long NowDevice::getCurrentProcessId()
{
	return (long) GetCurrentProcessId();
}

string NowDevice::getCurrentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%H-%M-%S", &tstruct);

	return buf;
}

std::string NowDevice::getCurrentDirectory()
{

	#define GetCurrentDir _getcwd

	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return "";
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	return string(cCurrentPath);
}

vector<string>* NowDevice::getAllFilesInDirectory(const string& strDirectory, const string& strExtension )
{
	vector<string>* lstReturn = new vector<string>();

	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError=0;

	// If the directory is not specified as a command-line argument,
	// print usage.

	/*if(argc != 2)
	{
		_tprintf(TEXT("\nUsage: %s <directory name>\n"), argv[0]);
		return (-1);
	}*/

	// Check that the input path plus 3 is not longer than MAX_PATH.
	// Three characters are for the "\*" plus NULL appended below.

	StringCchLength(strDirectory.c_str(), MAX_PATH, &length_of_arg);

	if (length_of_arg > (MAX_PATH - 3))
	{
		OutputDebugStringA("[NowDevice::getAllFilesInDirectory]Directory path is too long.");
		//_tprintf(TEXT("\nDirectory path is too long.\n"));
		return NULL;
	}

	//_tprintf(TEXT("\nTarget directory is %s\n\n"), strDirectory.c_str());

	// Prepare string for use with FindFile functions.  First, copy the
	// string to a buffer, then append '\*' to the directory name.

	StringCchCopy(szDir, MAX_PATH, strDirectory.c_str());
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	// Find the first file in the directory.

	hFind = FindFirstFile(szDir, &ffd);

	if (INVALID_HANDLE_VALUE == hFind) 
	{
		OutputDebugStringA("[NowDevice::getAllFilesInDirectory]FindFirstFile => ERROR");
		//DisplayErrorBox(TEXT("FindFirstFile"));
		return NULL;
	} 

	// List all the files in the directory with some info about them.

	do
	{
		//if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		//{
			//NowLogger::getInstance()->LogAString("[NowDevice::getAllFilesInDirectory] File:[" + string(ffd.cFileName)+ " <DIR>]");
			//_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
		//}
		//else
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_NORMAL)
		{
		}
		{
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			//_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
			string currentFile = string(ffd.cFileName);

			unsigned found = currentFile.find_last_of(".");

			if (strExtension.compare(currentFile.substr(found + 1)) == 0)
			{
				OutputDebugStringA(ffd.cFileName);
				lstReturn->push_back(string(ffd.cFileName));
			}
		}
	}
	while (FindNextFile(hFind, &ffd) != 0);

	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES) 
	{
		OutputDebugStringA("[NowDevice::getAllFilesInDirectory] FindFirstFile ERROR 2");
		//DisplayErrorBox(TEXT("FindFirstFile"));
	}

	FindClose(hFind);
	return lstReturn;
}

void NowDevice::sleep( int milisecond )
{
	Sleep(milisecond);
}

std::string NowDevice::getEnvironmentVariable( const string& strVariable )
{
	char* pPath = NULL;
	pPath = getenv(strVariable.c_str());
	if (pPath != NULL)
	{
		return string(pPath);
	}
	return "";
}

vector<wstring>* NowDevice::getFileData( const string& strFullPath )
{
	vector<wstring>* result = new vector<wstring>();
	System::String^ mstrFullPath = NowStringProcessor_UIA::StlStringToString(strFullPath);
	array<System::String^>^ text = System::IO::File::ReadAllLines(mstrFullPath);
	for (int i = 0; i < text->Length; i++)
	{
		result->push_back(NowStringProcessor_UIA::StringToStlWString(text[i]));
	}
	return result;
}
