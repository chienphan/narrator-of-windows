#include "NowControlBuilder.h"
#include "INowControl.h"
#include "NowStringProcessor.h"

#include "NowControl_UIA.h"
#include "NowButton_UIA.h"

NowControlBuilder* NowControlBuilder::m_Instance = NULL;

NowControlBuilder::NowControlBuilder(void)
{
}

NowControlBuilder::~NowControlBuilder(void)
{
}

NowControlBuilder* NowControlBuilder::getInstance()
{
	if (!m_Instance)
	{
		m_Instance = new NowControlBuilder();
	}
	return m_Instance;
}

INowControl* NowControlBuilder::createControlWrapper( string strSignatureControl, string strControlType )
{
	INowControl* pControl = NULL;
	if (NowStringProcessor::compareIgnoreCase(strControlType, NOW_CONTROL_BUTTON))
	{
		pControl = new NowButton_UIA(strSignatureControl, strControlType);
	}
	//TODO: implement create more control wrapper here!!!
	else
	{
		pControl = new NowControl_UIA(strSignatureControl, strControlType);
	}
	return pControl;
}
