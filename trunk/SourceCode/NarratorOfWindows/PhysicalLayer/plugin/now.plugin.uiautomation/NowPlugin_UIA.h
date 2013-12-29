#ifndef _NOW_PLUGIN_UIA_H_
#define _NOW_PLUGIN_UIA_H_

#include "NowDefine.h"
#include "INowPlugin.h"

//using namespace System::Windows::Automation;

class NowPlugin_UIA : INowPlugin
{
private:

	#pragma region Private properties and constructor

	//Signature of control
	string m_strControlSignature;

	static NowPlugin_UIA* m_pInstance;

	NowPlugin_UIA();

	#pragma endregion Private properties and constructor
	
	#pragma region Private methods


	#pragma endregion Private methods

public:

	#pragma region Public methods

	static NowPlugin_UIA* getInstance();
	~NowPlugin_UIA();

	#pragma endregion Public methods
	
	#pragma region Implement INowPlugin interface
	
	virtual string		getPluginName();

	virtual NOW_RESULT	getElementAtPoint( POINT point, INowControl*& pControl );

	virtual NOW_RESULT	clearCache();

	#pragma endregion Implement INowPlugin interface
};

#endif //_NOW_PLUGIN_UIA_H_