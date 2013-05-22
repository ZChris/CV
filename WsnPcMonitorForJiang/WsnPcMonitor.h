// WsnPcMonitor.h : main header file for the WSNPCMONITOR application
//

#if !defined(AFX_WSNPCMONITOR_H__034758CE_EE6E_4AFC_A7AF_2A62E0D0EBBA__INCLUDED_)
#define AFX_WSNPCMONITOR_H__034758CE_EE6E_4AFC_A7AF_2A62E0D0EBBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWsnPcMonitorApp:
// See WsnPcMonitor.cpp for the implementation of this class
//

class CWsnPcMonitorApp : public CWinApp
{
public:
	CWsnPcMonitorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWsnPcMonitorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWsnPcMonitorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WSNPCMONITOR_H__034758CE_EE6E_4AFC_A7AF_2A62E0D0EBBA__INCLUDED_)
