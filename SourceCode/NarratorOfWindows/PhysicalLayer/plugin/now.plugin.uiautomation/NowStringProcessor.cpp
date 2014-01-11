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

bool NowStringProcessor::compareIgnoreCase( const string& strFirst, const string& strSecond )
{
	bool blnResult = false;
	if (toLowerCase(strFirst).compare(toLowerCase(strSecond)) == 0)
	{
		blnResult = true;
	}
	return blnResult;
}

std::string NowStringProcessor::toLowerCase( const string& strNormal )
{
	string strReturn = strNormal;
	std::transform(strReturn.begin(), strReturn.end(), strReturn.begin(), ::tolower);
	return strReturn;
}

string NowStringProcessor::StringToStlString ( String ^ s ) 
{
	string os = "";
	using namespace Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

String^ NowStringProcessor::StlStringToString( string const& s )
{
	return gcnew String(s.c_str());
}



//std::string NowStringProcessor::IntToStlString( const int& number )
//{
//	return to_string((long)number);
//}


wstring NowStringProcessor::Utf8ToStlWString( const string& pUtfString)
{
	wstring stlString(pUtfString.begin(), pUtfString.end());
	//MAKE_WIDEPTR_FROMUTF8(pString, pUtfString);
	//stlString = pString;
	return stlString;
}
//
//void NowStringProcessor::Utf8ToStlWStringN( char const* pUtfString, ULONG length )
//{
//	wstring stlString;
//	MAKE_WIDEPTR_FROMUTF8N(pString, pUtfString, length);
//	stlString = pString;
//	return stlString;
//}
