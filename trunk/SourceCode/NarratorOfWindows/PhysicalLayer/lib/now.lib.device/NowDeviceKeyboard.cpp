#include "NowDeviceKeyboard.h"
#include "NowStringProcessor.h"

void NowDeviceKeyboard::sendKey( wstring content )
{
	System::String^ mstrContent = NowStringProcessor::StlWStringToString(content);
	System::Windows::Forms::SendKeys::SendWait(mstrContent);
}
