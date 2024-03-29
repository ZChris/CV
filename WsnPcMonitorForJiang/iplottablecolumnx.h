#if !defined(AFX_IPLOTTABLECOLUMNX_H__4FE0BFAE_2DBC_44D1_90AE_593D6BA80FBB__INCLUDED_)
#define AFX_IPLOTTABLECOLUMNX_H__4FE0BFAE_2DBC_44D1_90AE_593D6BA80FBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CiPlotTableColumnX wrapper class

class CiPlotTableColumnX : public COleDispatchDriver
{
public:
	CiPlotTableColumnX() {}		// Calls COleDispatchDriver default constructor
	CiPlotTableColumnX(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CiPlotTableColumnX(const CiPlotTableColumnX& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetTitle();
	void SetTitle(LPCTSTR lpszNewValue);
	double GetWidth();
	void SetWidth(double newValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	long GetTitleAlignment();
	void SetTitleAlignment(long nNewValue);
	double GetTitleAlignmentMargin();
	void SetTitleAlignmentMargin(double newValue);
	unsigned long GetTitleFontColor();
	void SetTitleFontColor(unsigned long newValue);
	long GetDataAlignment();
	void SetDataAlignment(long nNewValue);
	double GetDataAlignmentMargin();
	void SetDataAlignmentMargin(double newValue);
	unsigned long GetDataFontColor();
	void SetDataFontColor(unsigned long newValue);
	BOOL GetAutoSize();
	void SetAutoSize(BOOL bNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPLOTTABLECOLUMNX_H__4FE0BFAE_2DBC_44D1_90AE_593D6BA80FBB__INCLUDED_)
