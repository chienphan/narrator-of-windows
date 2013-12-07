#include "NowStringProcessor.h"


NowStringProcessor::NowStringProcessor(void)
{
}


NowStringProcessor::~NowStringProcessor(void)
{
}

wstring NowStringProcessor::StringToStlWString( String const^ s)
{
	wstring os;
	String^ string = const_cast<String^>(s);
	const wchar_t* chars = reinterpret_cast<const wchar_t*>((Marshal::StringToHGlobalUni(string)).ToPointer());
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

String^ NowStringProcessor::StlWStringToString( wstring const& os )
{
	String^ str = gcnew String(os.c_str());
	return str;
}

String^ NowStringProcessor::WPtrToString( wchar_t const* pData, int length )
{
	if (length == 0) {
		//use null termination
		length = wcslen(pData);
		if (length == 0) {
			System::String^ ret = "";
			return ret;
		}
	}

	System::IntPtr bfr = System::IntPtr(const_cast<wchar_t*>(pData));
	String^ ret = System::Runtime::InteropServices::Marshal::PtrToStringUni(bfr, length);
	return ret;
}

//wstring NowStringProcessor::Utf8ToStlWString( char const* pUtfString)
//{
//	wstring stlString;
//	MAKE_WIDEPTR_FROMUTF8(pString, pUtfString);
//	stlString = pString;
//	return stlString;
//}
//
//void NowStringProcessor::Utf8ToStlWStringN( char const* pUtfString, ULONG length )
//{
//	wstring stlString;
//	MAKE_WIDEPTR_FROMUTF8N(pString, pUtfString, length);
//	stlString = pString;
//	return stlString;
//}
