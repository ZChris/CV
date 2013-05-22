// WsnPcMonitorDlg.h : header file
//
#include "SerialPort.h"
//{{AFX_INCLUDES()
#include "iledroundx.h"
#include "ithermometerx.h"
#include "iplotx.h"
#include "iswitchrockerx.h"
#include "iledrectanglex.h"
#include "iledbarx.h"
//}}AFX_INCLUDES

#if !defined(AFX_WSNPCMONITORDLG_H__F83334FE_3526_411C_844F_2B9076DFDB93__INCLUDED_)
#define AFX_WSNPCMONITORDLG_H__F83334FE_3526_411C_844F_2B9076DFDB93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NETWORK_EVENT WM_USER+166 //定义网络事件

/////////////////////////////////////////////////////////////////////////////
// CWsnPcMonitorDlg dialog

class CWsnPcMonitorDlg : public CDialog
{
// Construction
public:
	void OperateLed(int ledID,BOOL staue);
	BOOL b_isSocketConnectFlag;
	CString tmpSendString;
	//CString tmpSendString;
	CString IpAddr;
	void OnIPAddress(void);
	double tempValueBuf[4];
	BOOL AlarmFlag[4];
	BOOL LedOnOffFlag[4];
	void ReceiveDataAnalysis();
	BOOL CheckReceiveData();
	int GetSystemPorts(CString *pNameList, CString *pPortList);
	CWsnPcMonitorDlg(CWnd* pParent = NULL);	// standard constructor

	SOCKET ClientSock[10]; //存储与客户端通信的Socket的数组	
	/*各种网络异步事件的处理函数*/	
	void OnClose(SOCKET CurSock); //对端Socket断开		
	void OnReceive(SOCKET CurSock); //网络数据包到达	
	void OnAccept(SOCKET CurSock); //客户端连接请求	
	BOOL InitNetwork(); //初始化网络函数	
	void OnNetEvent(WPARAM wParam, LPARAM lParam); //异步事件回调函数
	int Send(SOCKET fd,char *szText,int len);//调用socket发送数据

	CSerialPort m_SerialPort;
	BOOL m_bSerialPortOpened; //标志串口是否打开 
	int PortTab[10];

// Dialog Data
	//{{AFX_DATA(CWsnPcMonitorDlg)
	enum { IDD = IDD_WSNPCMONITOR_DIALOG };
	CIPAddressCtrl	m_IPAddress;
	CEdit	m_EditText;
	CComboBox	m_ComSel;
	CiLedRoundX	m_PortLedStatu;
	CString	m_temp1;
	CString	m_temp2;
	CString	m_temp3;
	CString	m_temp4;
	CiThermometerX	m_tempDisp1;
	CiThermometerX	m_tempDisp2;
	CiThermometerX	m_tempDisp3;
	CiThermometerX	m_tempDisp4;
	CiPlotX	m_plotx;
	int		m_Light1Level;
	int		m_Light2Level;
	int		m_Light3Level;
	int		m_Light4Level;
	float	m_Gas1;
	float	m_Gas2;
	float	m_Gas3;
	float	m_Gas4;
	CiSwitchRockerX	m_LedSwitch1;
	CiSwitchRockerX	m_LedSwitch2;
	CiSwitchRockerX	m_LedSwitch3;
	CiSwitchRockerX	m_LedSwitch4;
	int		m_SelectPlotIndex;
	CiLedRectangleX	m_Alarm1;
	CiLedRectangleX	m_Alarm2;
	CiLedRectangleX	m_Alarm3;
	CiLedRectangleX	m_Alarm4;
	CiLedBarX	m_ClientLeds;
	CiLedRectangleX	m_SocketServerEnabled;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWsnPcMonitorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	LONG OnComm(WPARAM ch, LPARAM port);

	// Generated message map functions
	//{{AFX_MSG(CWsnPcMonitorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnopen();
	afx_msg void OnBtnClose();
	afx_msg void OnBtnSend();
	afx_msg void OnOnChangeIswitchrockerx1();
	afx_msg void OnBtnout();
	afx_msg void OnAutoFlash();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnOnClickIswitchrockerx1();
	afx_msg void OnOnClickIswitchrockerx2();
	afx_msg void OnOnClickIswitchrockerx3();
	afx_msg void OnOnClickIswitchrockerx4();
	afx_msg void OnBtnStopFlash();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnBtnStartListen();
	afx_msg void OnBtnStopListen();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WSNPCMONITORDLG_H__F83334FE_3526_411C_844F_2B9076DFDB93__INCLUDED_)
