#ifndef _NOW_STRING_PROCESSOR_H_
#define _NOW_STRING_PROCESSOR_H_

#include "NowDefine.h"

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
	static String^ StlWStringToString (wstring const& os);
	static String^ WPtrToString(wchar_t const* pData, int length);
	/*static wstring Utf8ToStlWString(char const* pUtfString);
	static wstring Utf8ToStlWStringN(char const* pUtfString, ULONG length);*/
};

#endif


