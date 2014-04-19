#ifndef _NOW_STRING_PROCESSOR_UIA_H_
#define _NOW_STRING_PROCESSOR_UIA_H_

#include "NowDefine.h"
#include <algorithm>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace std;

class NowStringProcessor_UIA
{
private:
	NowStringProcessor_UIA(void);
	~NowStringProcessor_UIA(void);

public:
	static wstring StringToStlWString (String const^ s);
	static string StringToStlString ( String ^ s );
	static String^ StlStringToString(string const& s);
	static String^ StlWStringToString (wstring const& os);
	static String^ WPtrToString(wchar_t const* pData, int length);
};

#endif


