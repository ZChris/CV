// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "iledrectanglex.h"

// Dispatch interfaces referenced by this interface
#include "font.h"

/////////////////////////////////////////////////////////////////////////////
// CiLedRectangleX

IMPLEMENT_DYNCREATE(CiLedRectangleX, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CiLedRectangleX properties

/////////////////////////////////////////////////////////////////////////////
// CiLedRectangleX operations

BOOL CiLedRectangleX::GetActive()
{
	BOOL result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetActive(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

unsigned long CiLedRectangleX::GetActiveColor()
{
	unsigned long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetActiveColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long CiLedRectangleX::GetBevelStyle()
{
	long result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetBevelStyle(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CiLedRectangleX::GetVisible()
{
	BOOL result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CiLedRectangleX::GetEnabled()
{
	BOOL result;
	InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetEnabled(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void CiLedRectangleX::AboutBox()
{
	InvokeHelper(0xfffffdd8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CiLedRectangleX::ShowPropertyEditor()
{
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString CiLedRectangleX::GetCenterLabelText()
{
	CString result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetCenterLabelText(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

COleFont CiLedRectangleX::GetCenterLabelFont()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return COleFont(pDispatch);
}

void CiLedRectangleX::SetCenterLabelFont(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CiLedRectangleX::GetCenterLabelFontActiveColor()
{
	unsigned long result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetCenterLabelFontActiveColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

unsigned long CiLedRectangleX::GetCenterLabelFontInactiveColor()
{
	unsigned long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetCenterLabelFontInactiveColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

void CiLedRectangleX::SetActiveNoEvent(BOOL Value)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Value);
}

BOOL CiLedRectangleX::GetShowReflection()
{
	BOOL result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetShowReflection(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CiLedRectangleX::GetAutoInactiveColor()
{
	BOOL result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetAutoInactiveColor(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

unsigned long CiLedRectangleX::GetInactiveColor()
{
	unsigned long result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetInactiveColor(unsigned long newValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

void CiLedRectangleX::RepaintAll()
{
	InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CiLedRectangleX::BeginUpdate()
{
	InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CiLedRectangleX::EndUpdate()
{
	InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CiLedRectangleX::Lock()
{
	InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CiLedRectangleX::Unlock()
{
	InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CiLedRectangleX::GetCenterLabelWordWrap()
{
	BOOL result;
	InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetCenterLabelWordWrap(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long CiLedRectangleX::GetCenterLabelEndsMargin()
{
	long result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetCenterLabelEndsMargin(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CiLedRectangleX::GetCenterLabelAlignment()
{
	long result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetCenterLabelAlignment(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CiLedRectangleX::GetUpdateFrameRate()
{
	long result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetUpdateFrameRate(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CiLedRectangleX::GetComponentHandle()
{
	long result;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SaveImageToBitmap(LPCTSTR FileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName);
}

void CiLedRectangleX::SaveImageToMetaFile(LPCTSTR FileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName);
}

void CiLedRectangleX::SaveImageToJPEG(LPCTSTR FileName, long Compression, BOOL Progressive)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I4 VTS_BOOL;
	InvokeHelper(0x1b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName, Compression, Progressive);
}

long CiLedRectangleX::OPCAddItem()
{
	long result;
	InvokeHelper(0x1001, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CiLedRectangleX::OPCItemCount()
{
	long result;
	InvokeHelper(0x1002, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::OPCRemoveAllItems()
{
	InvokeHelper(0x1003, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CiLedRectangleX::OPCItemActivate(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1004, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}

void CiLedRectangleX::OPCItemDeactivate(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1005, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}

CString CiLedRectangleX::GetOPCItemComputerName(long Index)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1006, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Index);
	return result;
}

CString CiLedRectangleX::GetOPCItemServerName(long Index)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1007, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Index);
	return result;
}

CString CiLedRectangleX::GetOPCItemItemName(long Index)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1008, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Index);
	return result;
}

CString CiLedRectangleX::GetOPCItemPropertyName(long Index)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1009, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Index);
	return result;
}

BOOL CiLedRectangleX::GetOPCItemAutoConnect(long Index)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x100a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index);
	return result;
}

long CiLedRectangleX::GetOPCItemUpdateRate(long Index)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x100b, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Index);
	return result;
}

void CiLedRectangleX::SetOPCItemComputerName(long Index, LPCTSTR Value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x100c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index, Value);
}

void CiLedRectangleX::SetOPCItemServerName(long Index, LPCTSTR Value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x100d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index, Value);
}

void CiLedRectangleX::SetOPCItemItemName(long Index, LPCTSTR Value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x100e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index, Value);
}

void CiLedRectangleX::SetOPCItemPropertyName(long Index, LPCTSTR Value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x100f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index, Value);
}

void CiLedRectangleX::SetOPCItemAutoConnect(long Index, BOOL Value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BOOL;
	InvokeHelper(0x1010, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index, Value);
}

void CiLedRectangleX::SetOPCItemUpdateRate(long Index, long Value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x1011, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index, Value);
}

void CiLedRectangleX::OPCItemLoaded(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1012, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}

long CiLedRectangleX::GetObjectPointer()
{
	long result;
	InvokeHelper(0x1068, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

VARIANT CiLedRectangleX::GetBytesJPEG(long Compression, BOOL Progressive)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I4 VTS_BOOL;
	InvokeHelper(0x1069, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Compression, Progressive);
	return result;
}

void CiLedRectangleX::SavePropertiesToFile(LPCTSTR FileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x106a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName);
}

void CiLedRectangleX::LoadPropertiesFromFile(LPCTSTR FileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x106b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName);
}

BOOL CiLedRectangleX::GetOptionSaveAllProperties()
{
	BOOL result;
	InvokeHelper(0x106d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetOptionSaveAllProperties(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x106d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL CiLedRectangleX::GetAutoFrameRate()
{
	BOOL result;
	InvokeHelper(0x106e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetAutoFrameRate(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x106e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void CiLedRectangleX::iPaintToDC(long X, long Y, BOOL Transparent, long DC)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_BOOL VTS_I4;
	InvokeHelper(0x10cc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 X, Y, Transparent, DC);
}

long CiLedRectangleX::GetWidth()
{
	long result;
	InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetWidth(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CiLedRectangleX::GetHeight()
{
	long result;
	InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CiLedRectangleX::SetHeight(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void CiLedRectangleX::OPCItemUpdateResume(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1013, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}

void CiLedRectangleX::OPCItemUpdateSuspend(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1014, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}

VARIANT CiLedRectangleX::GetOPCItemData(long Index)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1015, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Index);
	return result;
}

short CiLedRectangleX::GetOPCItemQuality(long Index)
{
	short result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1016, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		Index);
	return result;
}

double CiLedRectangleX::GetOPCItemTimeStamp(long Index)
{
	double result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1017, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		Index);
	return result;
}

void CiLedRectangleX::SetOPCItemData(long Index, const VARIANT& Value)
{
	static BYTE parms[] =
		VTS_I4 VTS_VARIANT;
	InvokeHelper(0x1018, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index, &Value);
}

BOOL CiLedRectangleX::GetOPCItemActive(long Index)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1019, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Index);
	return result;
}

CString CiLedRectangleX::GetOPCItemGroupName(long Index)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x101a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Index);
	return result;
}

void CiLedRectangleX::SetOPCItemGroupName(long Index, LPCTSTR Value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x101b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index, Value);
}

void CiLedRectangleX::OPCDeleteItem(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x101c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}

void CiLedRectangleX::OPCItemActivateSuspend(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x101d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}

VARIANT CiLedRectangleX::GetBytesPNG(long Compression)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1020, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Compression);
	return result;
}

void CiLedRectangleX::SaveImageToPNG(LPCTSTR FileName, long Compression)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0x1021, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 FileName, Compression);
}
