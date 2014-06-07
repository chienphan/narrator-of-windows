#ifndef _NOW_TITLE_BAR_UIA_H_
#define _NOW_TITLE_BAR_UIA_H_

#include "NowDefine.h"
#include "INowControl.h"
#include "NowControl_UIA.h"

class NowTitleBar_UIA : public NowControl_UIA
{
public:
	NowTitleBar_UIA(string strSignature, string strControlType);

	~NowTitleBar_UIA(void);

	////virtual NOW_RESULT getControlType( string& strControlType );

	//virtual NOW_RESULT getCaption( wstring& wstrCaption );

	virtual NOW_RESULT getUIInformation( wstring& wstrHelpText );

	//virtual NOW_RESULT getParent( INowControl*& ctrParent );

	//virtual NOW_RESULT getChildren( list<INowControl*>& lstChildren );

	//virtual NOW_RESULT getState( int& nState );

	//virtual NOW_RESULT getSignature( string& strSignature );

	//virtual NOW_RESULT getNowClass( string& strNowClass );

	//virtual NOW_RESULT getToolTip( wstring& wstrToolTip);

};

#endif
