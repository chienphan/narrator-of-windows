#ifndef _NOW_STRING_PROCESSOR_H_
#define _NOW_STRING_PROCESSOR_H_

#include "NowDefine.h"
#include <algorithm>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace std;

class NowStringProcessor
{
private:
	NowStringProcessor(void);
	~NowStringProcessor(void);

public:
	static wstring StringToStlWString (String const^ s);
	static string StringToStlString ( String ^ s );
	static String^ StlStringToString(string const& s);
	static String^ StlWStringToString (wstring const& os);
	static String^ WPtrToString(wchar_t const* pData, int length);
	static bool compareIgnoreCase(const string& strFirst, const string& strSecond);
	static string toLowerCase(const string& strNormal);

	//static string IntToStlString(const int& number);
	static wstring Utf8ToStlWString(const string & pUtfString);
	/*static wstring Utf8ToStlWStringN(char const* pUtfString, ULONG length);*/
};

#endif


