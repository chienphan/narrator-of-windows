#ifndef _NOW_PLUGIN_UIA_H_
#define _NOW_PLUGIN_UIA_H_

#include "INowPlugin.h"
#include "NowDefine.h"

using namespace System::Windows::Automation;

class NowPlugin_UIA : INowPlugin
{
private:

	#pragma region Private properties and constructor

	string m_strControlSignature;
	string m_strPluginName;
	static NowPlugin_UIA* m_pInstance;
	NowPlugin_UIA();

	#pragma endregion Private properties and constructor
	
	#pragma region Private methods

	/*
	* Check for changed control
	*/
	bool isChangedControl(AutomationElement^ runtimeElement);

	/*
	* Get signature of control
	*/
	string getSignatureControl(AutomationElement^ runtimeElement);

	#pragma endregion Private methods

public:

	#pragma region Public methods

	static NowPlugin_UIA* getInstance();
	~NowPlugin_UIA();

	#pragma endregion Public methods
	
	#pragma region Implement INowPlugin interface
	
	virtual string getPluginName();
	virtual NOW_RESULT getElementAtPoint( POINT point, NowControl*& pControl );
	
	#pragma endregion Implement INowPlugin interface
};

#endif //_NOW_PLUGIN_UIA_H_