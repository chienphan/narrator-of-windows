// UIAutomationAPIDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <UIAutomation.h>
#include <UIAutomationClient.h>
#include "UIAPlugin.h"


int _tmain(int argc, _TCHAR* argv[])
{
	UIAPlugin* currentPlugin = UIAPlugin::getInstance();
}


HRESULT InitializeUIAutomation(IUIAutomation **ppAutomation)
{
    return CoCreateInstance(CLSID_CUIAutomation, NULL,
        CLSCTX_INPROC_SERVER, IID_IUIAutomation, 
        reinterpret_cast<void**>(ppAutomation));
}

std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen)
{
    int len = ::WideCharToMultiByte(CP_ACP, 0, pstr, wslen, NULL, 0, NULL, NULL);

    std::string dblstr(len, '\0');
    len = ::WideCharToMultiByte(CP_ACP, 0 /* no flags */,
                                pstr, wslen /* not necessary NULL-terminated */,
                                &dblstr[0], len,
                                NULL, NULL /* no default char */);

    return dblstr;
}

BSTR ConvertMBSToBSTR(const std::string& str)
{
    int wslen = ::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
                                      str.data(), str.length(),
                                      NULL, 0);

    BSTR wsdata = ::SysAllocStringLen(NULL, wslen);
    ::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
                          str.data(), str.length(),
                          wsdata, wslen);
    return wsdata;
}

std::string ConvertBSTRToMBS(BSTR bstr)
{
    int wslen = ::SysStringLen(bstr);
    return ConvertWCSToMBS((wchar_t*)bstr, wslen);
}


/*
int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);
	HRESULT hResult;
	IUIAutomation* automation;
	hResult = InitializeUIAutomation(&automation);

	if(hResult == S_OK)
	{
		IUIAutomationElement* rootElement;
		hResult = automation->GetRootElement(&rootElement);
		if(hResult == S_OK)
		{
			IUIAutomationCondition* trueCondition;
			hResult = automation->CreateTrueCondition(&trueCondition);
			if(hResult == S_OK)
			{
				IUIAutomationElementArray* listElement;
				hResult = rootElement->FindAll(TreeScope_Children, trueCondition, &listElement);
				if(hResult == S_OK)
				{
					IUIAutomationElement* currentElement;
					int nLength = 0;
					int i = 0;
					listElement->get_Length(&nLength);
					for(int index = 0; index < nLength; index++)
					{
						hResult = listElement->GetElement(index, &currentElement);
						if(hResult == S_OK)
						{
							VARIANT retVal;
							currentElement->GetCurrentPropertyValue(UIA_NamePropertyId, &retVal);
							
							if(strlen((const char*)retVal.bstrVal) > 0)
							{
								std::string strTemp = ConvertBSTRToMBS(retVal.bstrVal);
								printf("[%d] %s\n", ++i, strTemp.c_str());
							}
						}
					}
				}
			}
		}

	}

	system("pause");
	return 0;
}*/