#if !defined(AFX_IPLOTTABLEX_H__D78D15CC_6466_49D8_8EF7_075E4D833161__INCLUDED_)
#define AFX_IPLOTTABLEX_H__D78D15CC_6466_49D8_8EF7_075E4D833161__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class COleFont;
class CiPlotTableColumnX;

/////////////////////////////////////////////////////////////////////////////
// CiPlotTableX wrapper class

class CiPlotTableX : public COleDispatchDriver
{
public:
	CiPlotTableX() {}		// Calls COleDispatchDriver default constructor
	CiPlotTableX(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CiPlotTableX(const CiPlotTableX& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetMarginLeft();
	void SetMarginLeft(double newValue);
	double GetMarginTop();
	void SetMarginTop(double newValue);
	double GetMarginRight();
	void SetMarginRight(double newValue);
	double GetMarginBottom();
	void SetMarginBottom(double newValue);
	unsigned long GetGridBackGroundColor();
	void SetGridBackGroundColor(unsigned long newValue);
	BOOL GetGridBackGroundTransparent();
	void SetGridBackGroundTransparent(BOOL bNewValue);
	unsigned long GetGridLinesColor();
	void SetGridLinesColor(unsigned long newValue);
	BOOL GetGridLinesShow();
	void SetGridLinesShow(BOOL bNewValue);
	COleFont GetDataFont();
	void SetDataFont(LPDISPATCH newValue);
	unsigned long GetDataFontColor();
	void SetDataFontColor(unsigned long newValue);
	double GetColumnSpacing();
	void SetColumnSpacing(double newValue);
	double GetRowSpacing();
	void SetRowSpacing(double newValue);
	long GetRowsMax();
	void SetRowsMax(long nNewValue);
	BOOL GetColumnTitlesVisible();
	void SetColumnTitlesVisible(BOOL bNewValue);
	COleFont GetColumnTitlesFont();
	void SetColumnTitlesFont(LPDISPATCH newValue);
	unsigned long GetColumnTitlesFontColor();
	void SetColumnTitlesFontColor(unsigned long newValue);
	long AddColumn(LPCTSTR Title);
	void RemoveAllColumns();
	void RemoveAllRows();
	void DeleteColumn(long Index);
	void DeleteRow(long Index);
	long GetRowCount();
	long GetColumnCount();
	CString GetData(long Col, long Row);
	void SetData(long Col, long Row, LPCTSTR lpszNewValue);
	CiPlotTableColumnX GetColumn(long Index);
	long AddRow();
	BOOL GetEnabled();
	void SetEnabled(BOOL bNewValue);
	BOOL GetPopupEnabled();
	void SetPopupEnabled(BOOL bNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	CString GetName();
	void SetName(LPCTSTR lpszNewValue);
	long GetLayer();
	void SetLayer(long nNewValue);
	BOOL GetUserSelected();
	void SetUserSelected(BOOL bNewValue);
	long GetZOrder();
	void SetZOrder(long nNewValue);
	double GetStartPercent();
	void SetStartPercent(double newValue);
	double GetStopPercent();
	void SetStopPercent(double newValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPLOTTABLEX_H__D78D15CC_6466_49D8_8EF7_075E4D833161__INCLUDED_)
