// Copyright (C) FlatGlobus(wtlbuilder@gmail.com) All rights reserved.
//
// This file is a part of the WTLBuilder.
// The use and distribution terms for this software are covered by the
// Microsoft Public License (http://opensource.org/licenses/MS-PL)
// which can be found in the file MS-PL.txt at the root folder.

#ifndef __DIALOGIMPL_H
#define __DIALOGIMPL_H
//////////////////////////////////////////////////////////////////////////
namespace Form
{
class CDialogImpl:public CFormComponent
{
public:
	DECLARE_FRAME_WND_CLASS(NULL, IDI_FORM)

	CDialogImpl(LPTSTR _name=NULL);
	~CDialogImpl(void);

 //  BEGIN_MSG_MAP_EX(CDialogImpl)
	//	CHAIN_MSG_MAP(CFormComponent<CDialogImpl>)
	//	CHAIN_MSG_MAP(thisClass)
	//	REFLECT_NOTIFICATIONS_EX()
	//END_MSG_MAP()

	virtual BOOL CreateComponent(Component *);
	virtual void OnFinalMessage(HWND /*hWnd*/);
    virtual void InitProperty(void);
    virtual CRect GetMinRect();
    //DECLARE_PROPERTY(Center,CString)
    
};
}
//////////////////////////////////////////////////////////////////////////
#endif