#if !defined(AFX_IPLOTX_H__82248D1D_28EC_4B9C_8F33_05DD5AA54E32__INCLUDED_)
#define AFX_IPLOTX_H__82248D1D_28EC_4B9C_8F33_05DD5AA54E32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CiPlotAxisX;
class CiPlotLegendX;
class CiPlotToolBarX;
class CiPlotDataViewX;
class COleFont;
class CiPlotAnnotationX;
class CPicture;
class CiPlotDataCursorX;
class CiPlotLimitX;
class CiPlotLabelX;
class CiPlotTableX;
class CiPlotChannelX;

/////////////////////////////////////////////////////////////////////////////
// CiPlotX wrapper class

class CiPlotX : public CWnd
{
protected:
	DECLARE_DYNCREATE(CiPlotX)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x1791c036, 0x8981, 0x492a, { 0xbd, 0x28, 0xf2, 0x33, 0x1b, 0xc9, 0xb7, 0xc7 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	long GetDataViewZHorz();
	void SetDataViewZHorz(long nNewValue);
	long GetDataViewZVert();
	void SetDataViewZVert(long nNewValue);
	BOOL GetXYAxesReverse();
	void SetXYAxesReverse(BOOL bNewValue);
	long GetOuterMarginLeft();
	void SetOuterMarginLeft(long nNewValue);
	long GetOuterMarginTop();
	void SetOuterMarginTop(long nNewValue);
	long GetOuterMarginRight();
	void SetOuterMarginRight(long nNewValue);
	long GetOuterMarginBottom();
	void SetOuterMarginBottom(long nNewValue);
	long GetPrintOrientation();
	void SetPrintOrientation(long nNewValue);
	double GetPrintMarginLeft();
	void SetPrintMarginLeft(double newValue);
	double GetPrintMarginTop();
	void SetPrintMarginTop(double newValue);
	double GetPrintMarginRight();
	void SetPrintMarginRight(double newValue);
	double GetPrintMarginBottom();
	void SetPrintMarginBottom(double newValue);
	BOOL GetPrintShowDialog();
	void SetPrintShowDialog(BOOL bNewValue);
	long GetUpdateFrameRate();
	void SetUpdateFrameRate(long nNewValue);
	unsigned long GetBackGroundColor();
	void SetBackGroundColor(unsigned long newValue);
	long GetBorderStyle();
	void SetBorderStyle(long nNewValue);
	BOOL GetAutoFrameRate();
	void SetAutoFrameRate(BOOL bNewValue);
	void AboutBox();
	CiPlotAxisX GetXAxis(long Index);
	CiPlotAxisX GetYAxis(long Index);
	CiPlotLegendX GetLegend(long Index);
	CiPlotToolBarX GetToolBar(long Index);
	CiPlotDataViewX GetDataView(long Index);
	void DisableLayoutManager();
	void EnableLayoutManager();
	void DisableAllTracking();
	void EnableAllTracking();
	long AddXAxis();
	long AddYAxis();
	long AddLegend();
	long AddToolBar();
	long AddDataView();
	long AddChannel();
	void RemoveAllXAxes();
	void RemoveAllYAxes();
	void RemoveAllLegends();
	void RemoveAllToolBars();
	void RemoveAllDataViews();
	void RemoveAllChannels();
	long GetXAxisCount();
	long GetYAxisCount();
	long GetLegendCount();
	long GetToolBarCount();
	long GetDataViewCount();
	long GetChannelCount();
	BOOL GetHintsShow();
	void SetHintsShow(BOOL bNewValue);
	long GetHintsPause();
	void SetHintsPause(long nNewValue);
	long GetHintsHidePause();
	void SetHintsHidePause(long nNewValue);
	void DeleteToolBar(long Index);
	void DeleteLegend(long Index);
	void DeleteXAxis(long Index);
	void DeleteYAxis(long Index);
	void DeleteChannel(long Index);
	void DeleteDataView(long Index);
	void ShowPropertyEditor();
	BOOL GetTitleVisible();
	void SetTitleVisible(BOOL bNewValue);
	CString GetTitleText();
	void SetTitleText(LPCTSTR lpszNewValue);
	double GetTitleMargin();
	void SetTitleMargin(double newValue);
	COleFont GetTitleFont();
	void SetTitleFont(LPDISPATCH newValue);
	unsigned long GetTitleFontColor();
	void SetTitleFontColor(unsigned long newValue);
	void RemoveAllAnnotations();
	void DeleteAnnotation(long Index);
	long AddAnnotation();
	long GetAnnotationCount();
	CiPlotAnnotationX GetAnnotation(long Index);
	long GetChannelIndexByName(LPCTSTR Value);
	long GetXAxisIndexByName(LPCTSTR Value);
	long GetYAxisIndexByName(LPCTSTR Value);
	BOOL GetUserCanEditObjects();
	void SetUserCanEditObjects(BOOL bNewValue);
	void PrintChart();
	void CopyToClipBoard();
	void Save();
	CPicture GetSnapShotPicture();
	void RepaintAll();
	void BeginUpdate();
	void EndUpdate();
	void Lock();
	void Unlock();
	void ClearAllData();
	void AddDataArray(double XValue, const VARIANT& Data);
	double GetNow();
	void SavePropertiesToFile(LPCTSTR FileName);
	void LoadPropertiesFromFile(LPCTSTR FileName);
	void SaveDataToFile(LPCTSTR FileName);
	void LoadDataFromFile(LPCTSTR FileName);
	CString GetLogFileName();
	void SetLogFileName(LPCTSTR lpszNewValue);
	long GetLogBufferSize();
	void SetLogBufferSize(long nNewValue);
	void LogActivate(BOOL Append);
	void LogDeactivate();
	BOOL GetLoggingActive();
	long GetComponentHandle();
	CiPlotDataCursorX GetDataCursor(long Index);
	long GetDataCursorCount();
	long AddDataCursor();
	void DeleteDataCursor(long Index);
	void RemoveAllDataCursors();
	CiPlotLimitX GetLimit(long Index);
	long GetLimitCount();
	long AddLimit();
	void DeleteLimit(long Index);
	void RemoveAllLimits();
	void SaveImageToBitmap(LPCTSTR FileName);
	void SaveImageToMetaFile(LPCTSTR FileName);
	void SaveImageToJPEG(LPCTSTR FileName, long Compression, BOOL Progressive);
	void SaveTranslationsToFile(LPCTSTR FileName);
	void LoadTranslationsFromFile(LPCTSTR FileName);
	void RemoveAllTranslations();
	void DeleteTranslation(long Index);
	long AddTranslation(LPCTSTR OriginalString, LPCTSTR ReplacementString);
	long TranslationCount();
	CString GetTranslationOriginalString(long Index);
	CString GetTranslationReplacementString(long Index);
	CiPlotLabelX GetLabels(long Index);
	long GetLabelCount();
	long AddLabel();
	void DeleteLabel(long Index);
	void RemoveAllLabels();
	VARIANT GetBytesJPEG(long Compression, BOOL Progressive);
	long GetObjectPointer();
	BOOL GetOptionSaveAllProperties();
	void SetOptionSaveAllProperties(BOOL bNewValue);
	COleFont GetHintsFont();
	void SetHintsFont(LPDISPATCH newValue);
	unsigned long GetHintsFontColor();
	void SetHintsFontColor(unsigned long newValue);
	COleFont GetAnnotationDefaultFont();
	void SetAnnotationDefaultFont(LPDISPATCH newValue);
	unsigned long GetAnnotationDefaultFontColor();
	void SetAnnotationDefaultFontColor(unsigned long newValue);
	long GetAnnotationDefaultBrushStlye();
	void SetAnnotationDefaultBrushStlye(long nNewValue);
	unsigned long GetAnnotationDefaultBrushColor();
	void SetAnnotationDefaultBrushColor(unsigned long newValue);
	long GetAnnotationDefaultPenStlye();
	void SetAnnotationDefaultPenStlye(long nNewValue);
	unsigned long GetAnnotationDefaultPenColor();
	void SetAnnotationDefaultPenColor(unsigned long newValue);
	long GetAnnotationDefaultPenWidth();
	void SetAnnotationDefaultPenWidth(long nNewValue);
	long GetWidth();
	void SetWidth(long nNewValue);
	long GetHeight();
	void SetHeight(long nNewValue);
	BOOL GetUserCanAddRemoveChannels();
	void SetUserCanAddRemoveChannels(BOOL bNewValue);
	void SaveAnnotationsToFile(LPCTSTR FileName);
	void LoadAnnotationsFromFile(LPCTSTR FileName);
	void iPaintToDC(long X, long Y, BOOL Transparent, long DC);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	BOOL GetEnabled();
	void SetEnabled(BOOL bNewValue);
	long GetEditorFormStyle();
	void SetEditorFormStyle(long nNewValue);
	long GetCopyToClipBoardFormat();
	void SetCopyToClipBoardFormat(long nNewValue);
	CString GetPrintDocumentName();
	void SetPrintDocumentName(LPCTSTR lpszNewValue);
	void ImageListClear(long ImageListIndex);
	void ImageListLoadFromResourceID(long ImageListIndex, unsigned long Instance, long ResID);
	void ImageListLoadFromResourceName(long ImageListIndex, unsigned long Instance, LPCTSTR ResName);
	CString GetPrinterName();
	void SetPrinterName(LPCTSTR lpszNewValue);
	BOOL GetClipAnnotationsToAxes();
	void SetClipAnnotationsToAxes(BOOL bNewValue);
	BOOL GetBackGroundGradientEnabled();
	void SetBackGroundGradientEnabled(BOOL bNewValue);
	long GetBackGroundGradientDirection();
	void SetBackGroundGradientDirection(long nNewValue);
	unsigned long GetBackGroundGradientStartColor();
	void SetBackGroundGradientStartColor(unsigned long newValue);
	unsigned long GetBackGroundGradientStopColor();
	void SetBackGroundGradientStopColor(unsigned long newValue);
	CiPlotTableX GetTable(long Index);
	long GetTableCount();
	long AddTable();
	void DeleteTable(long Index);
	void RemoveAllTables();
	void ReCalcLayout();
	void TransferChannelData(long SourceChannelIndex, long DestinationChannelIndex, long StartIndex, long StopIndex);
	void ImageListAdd(long ImageListIndex, LPDISPATCH APicture);
	long GetDataFileColumnSeparator();
	void SetDataFileColumnSeparator(long nNewValue);
	long GetDataFileFormat();
	void SetDataFileFormat(long nNewValue);
	CString GetLastPropertiesFileName();
	CString GetLastDataFileName();
	long GetDataViewIndexByName(LPCTSTR Value);
	long GetToolBarIndexByName(LPCTSTR Value);
	long GetLegendIndexByName(LPCTSTR Value);
	long GetAnnotationIndexByName(LPCTSTR Value);
	long GetDataCursorIndexByName(LPCTSTR Value);
	long GetLabelIndexByName(LPCTSTR Value);
	long GetLimitIndexByName(LPCTSTR Value);
	long GetTableIndexByName(LPCTSTR Value);
	CiPlotToolBarX GetToolBarByName(LPCTSTR Value);
	CiPlotLegendX GetLegendByName(LPCTSTR Value);
	CiPlotTableX GetTableByName(LPCTSTR Value);
	CiPlotAxisX GetXAxisByName(LPCTSTR Value);
	CiPlotAxisX GetYAxisByName(LPCTSTR Value);
	CiPlotDataViewX GetDataViewByName(LPCTSTR Value);
	CiPlotDataCursorX GetDataCursorByName(LPCTSTR Value);
	CiPlotLimitX GetLimitByName(LPCTSTR Value);
	CiPlotLabelX GetLabelByName(LPCTSTR Value);
	CiPlotAnnotationX GetAnnotationByName(LPCTSTR Value);
	VARIANT GetBytesPNG(long Compression);
	void SaveImageToPNG(LPCTSTR FileName, long Compression);
	CiPlotChannelX GetChannel(long Index);
	CiPlotChannelX GetChannelByName(LPCTSTR Value);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPLOTX_H__82248D1D_28EC_4B9C_8F33_05DD5AA54E32__INCLUDED_)
