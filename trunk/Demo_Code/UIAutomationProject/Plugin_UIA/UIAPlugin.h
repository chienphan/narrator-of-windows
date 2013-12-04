#ifndef _UIAPLUGIN_H_
#define _UIAPLUGIN_H_

#include <vector>

class UIAPlugin
{

private:
	

	//Constructor and Destructor
	UIAPlugin() {};
	~UIAPlugin() {};

public:
	static UIAPlugin* m_UIAPlugin;
	static UIAPlugin*	getInstance()
	{
		if (!m_UIAPlugin)
		{
			m_UIAPlugin = new UIAPlugin();
		}
		return m_UIAPlugin;
	};
	std::vector<int>	getAllHandleWindows();
};

#endif //_UIAPLUGIN_H_


