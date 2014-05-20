#ifndef _NOW_LIST_ITEM_UIA_H
#define _NOW_LIST_ITEM_UIA_H

#include "NowDefine.h"
#include "INowControl.h"
#include "NowControl_UIA.h"

class NowListItem_UIA : public NowControl_UIA
{

public:
	NowListItem_UIA(string strSignature, string strControlType);
	~NowListItem_UIA(void);

	//virtual NOW_RESULT getControlType( string& strControlType );

	//virtual NOW_RESULT getCaption( wstring& wstrCaption );

	virtual NOW_RESULT getUIInformation( wstring& wstrHelpText );

	virtual NOW_RESULT scrollIntoView();

	//virtual NOW_RESULT getParent( INowControl*& ctrParent );

	//virtual NOW_RESULT getChildren( list<INowControl*>& lstChildren );

	//virtual NOW_RESULT getState( int& nState );

	//virtual NOW_RESULT getSignature( string& strSignature );

	//virtual NOW_RESULT getNowClass( string& strNowClass );

	//virtual NOW_RESULT getToolTip( wstring& wstrToolTip);
};

#endif

