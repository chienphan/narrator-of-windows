#include "NowStringProcessor_UIA.h"


NowStringProcessor_UIA::NowStringProcessor_UIA(void)
{
}


NowStringProcessor_UIA::~NowStringProcessor_UIA(void)
{
}

wstring NowStringProcessor_UIA::StringToStlWString( String const^ s)
{
	wstring os;
	String^ string = const_cast<String^>(s);
	const wchar_t* chars = reinterpret_cast<const wchar_t*>((Marshal::StringToHGlobalUni(string)).ToPointer());
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

String^ NowStringProcessor_UIA::StlWStringToString( wstring const& os )
{
	String^ str = gcnew String(os.c_str());
	return str;
}

String^ NowStringProcessor_UIA::WPtrToString( wchar_t const* pData, int length )
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


string NowStringProcessor_UIA::StringToStlString ( String ^ s ) 
{
	string os = "";
	using namespace Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

String^ NowStringProcessor_UIA::StlStringToString( string const& s )
{
	return gcnew String(s.c_str());
}



