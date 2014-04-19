#include "NowDeviceKeyboard.h"
#include "NowStringProcessor_UIA.h"

void NowDeviceKeyboard::sendKey( wstring content )
{
	System::String^ mstrContent = NowStringProcessor_UIA::StlWStringToString(content);
	System::Windows::Forms::SendKeys::SendWait(mstrContent);
}

void NowDeviceKeyboard::sendKey( string content )
{
	System::String^ mstrContent = NowStringProcessor_UIA::StlStringToString(content);
	System::Windows::Forms::SendKeys::SendWait(mstrContent);
}
