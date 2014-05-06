#include "NowEdit_UIA.h"
#include "..\NowCommunication.h"

NowEdit_UIA::NowEdit_UIA(string strSignature, string strControlType) : NowControl_UIA(strSignature, strControlType)
{
}


NowEdit_UIA::~NowEdit_UIA(void)
{
}

NOW_RESULT NowEdit_UIA::setValue( const wstring& wstrValue )
{
	return NowCommunication::getInstance()->setValue(m_strSignature, wstrValue);
}
