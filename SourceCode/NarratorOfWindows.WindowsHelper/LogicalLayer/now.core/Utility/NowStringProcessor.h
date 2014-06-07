#ifndef _NOW_STRING_PROCESSOR_H_
#define _NOW_STRING_PROCESSOR_H_

#include "NowDefine.h"
#include <algorithm>

class DllExport NowStringProcessor
{
public:

	static bool compareIgnoreCase(const string& strFirst, const string& strSecond);
	static string toLowerCase(const string& strNormal);

	//static string IntToStlString(const int& number);
	static wstring Utf8ToStlWString(const string & pUtfString);
	//static wstring Utf8ToStlWStringN(char const* pUtfString, ULONG length);
	static string wstringTostring(const wstring & inString);
	//static wstring stringToWstring(const string & inString);

	static vector<string>* split(const std::string& source, char delim);
	static vector<wstring>* split(const std::wstring& source, wchar_t delim);
};

#endif


