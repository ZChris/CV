// WsnPcMonitorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WsnPcMonitor.h"
#include "WsnPcMonitorDlg.h"
#include "iPlotChannelX.h"
#include "iPlotAxisX.h"

#include <atlbase.h>//����Ҫ����ͷ�ļ�

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DEFAULT_PORT 51706

SOCKET ServerSock;//��������Socket
SOCKET ClientSocket;//client socket
char SendBuf[50];
char szBuf[1024];
BYTE dataReceive[6];
int	 r_index = -1;	//������ǰRcvDataBuf��Ҫ�����ڼ������� �̡�

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWsnPcMonitorDlg dialog

CWsnPcMonitorDlg::CWsnPcMonitorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWsnPcMonitorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWsnPcMonitorDlg)
	m_temp1 = _T("+ 0.0");
	m_temp2 = _T("+ 0.0");
	m_temp3 = _T("+ 0.0");
	m_temp4 = _T("+ 0.0");
	m_Light1Level = 0;
	m_Light2Level = 0;
	m_Light3Level = 0;
	m_Light4Level = 0;
	m_Gas1 = 0.0f;
	m_Gas2 = 0.0f;
	m_Gas3 = 0.0f;
	m_Gas4 = 0.0f;
	m_SelectPlotIndex = 0;
	b_isSocketConnectFlag = FALSE;
	LedOnOffFlag[0] = FALSE;
	LedOnOffFlag[1] = FALSE;
	LedOnOffFlag[2] = FALSE;
	LedOnOffFlag[3] = FALSE;
	AlarmFlag[0] = FALSE;
	AlarmFlag[1] = FALSE;
	AlarmFlag[2] = FALSE;
	AlarmFlag[3] = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWsnPcMonitorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWsnPcMonitorDlg)
	DDX_Control(pDX, IDC_IPADDRESS, m_IPAddress);
	DDX_Control(pDX, IDC_EDIT_REVMSG, m_EditText);
	DDX_Control(pDX, IDC_COMBOPORT, m_ComSel);
	DDX_Control(pDX, IDC_ILEDPORT, m_PortLedStatu);
	DDX_Text(pDX, IDC_TMP1, m_temp1);
	DDX_Text(pDX, IDC_TMP2, m_temp2);
	DDX_Text(pDX, IDC_TMP3, m_temp3);
	DDX_Text(pDX, IDC_TMP4, m_temp4);
	DDX_Control(pDX, IDC_ITHERMOMETERX1, m_tempDisp1);
	DDX_Control(pDX, IDC_ITHERMOMETERX2, m_tempDisp2);
	DDX_Control(pDX, IDC_ITHERMOMETERX3, m_tempDisp3);
	DDX_Control(pDX, IDC_ITHERMOMETERX4, m_tempDisp4);
	DDX_Control(pDX, IDC_IPLOTX1, m_plotx);
	DDX_Text(pDX, IDC_LIGHTLEVEL1, m_Light1Level);
	DDX_Text(pDX, IDC_LIGHTLEVEL2, m_Light2Level);
	DDX_Text(pDX, IDC_LIGHTLEVEL3, m_Light3Level);
	DDX_Text(pDX, IDC_LIGHTLEVEL4, m_Light4Level);
	DDX_Text(pDX, IDC_GAS1, m_Gas1);
	DDX_Text(pDX, IDC_GAS2, m_Gas2);
	DDX_Text(pDX, IDC_GAS3, m_Gas3);
	DDX_Text(pDX, IDC_GAS4, m_Gas4);
	DDX_Control(pDX, IDC_ISWITCHROCKERX1, m_LedSwitch1);
	DDX_Control(pDX, IDC_ISWITCHROCKERX2, m_LedSwitch2);
	DDX_Control(pDX, IDC_ISWITCHROCKERX3, m_LedSwitch3);
	DDX_Control(pDX, IDC_ISWITCHROCKERX4, m_LedSwitch4);
	DDX_Radio(pDX, IDC_RADIO1, m_SelectPlotIndex);
	DDX_Control(pDX, IDC_ILEDRECTANGLEX1, m_Alarm1);
	DDX_Control(pDX, IDC_ILEDRECTANGLEX2, m_Alarm2);
	DDX_Control(pDX, IDC_ILEDRECTANGLEX3, m_Alarm3);
	DDX_Control(pDX, IDC_ILEDRECTANGLEX4, m_Alarm4);
	DDX_Control(pDX, IDC_CLIENTLEDS, m_ClientLeds);
	DDX_Control(pDX, IDC_SOCKETSERVER, m_SocketServerEnabled);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWsnPcMonitorDlg, CDialog)
	//{{AFX_MSG_MAP(CWsnPcMonitorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNOPEN, OnBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnClose)
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	ON_BN_CLICKED(IDC_BTNOUT, OnBtnout)
	ON_BN_CLICKED(IDC_BTNAUTOUPLOAD, OnAutoFlash)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnBtnStopFlash)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_BUTTON3, OnBtnStartListen)
	ON_MESSAGE(WM_COMM_RXCHAR, OnComm)
	ON_BN_CLICKED(IDC_BUTTON4, OnBtnStopListen)
	ON_MESSAGE(NETWORK_EVENT,OnNetEvent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWsnPcMonitorDlg message handlers

BOOL CWsnPcMonitorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//��ȡϵͳ�еĴ��ڸ���
	CString pNameList[10];
	CString pPortList[10];
	int SerialCount=GetSystemPorts(pNameList,pPortList);
	//��Combo Box����Ӵ��ڸ���
	for(int j=0;j<SerialCount;j++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBOPORT))->AddString(pPortList[j]);
		PortTab[j] = pPortList[j].GetAt(3)-0x30;
	}

	m_ComSel.SetCurSel(0);      //�趨��ʼѡ��com��

	GetDlgItem(IDC_BTNCLOSE)->EnableWindow(FALSE);

	GetDlgItem(IDC_BTN_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTNAUTOUPLOAD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);

	//��ȡ����Ip��ַ
	OnIPAddress();
	//m_IPAddress.SetAddress(10,121,11,111);
	m_IPAddress.SetWindowText(IpAddr); // ��IP��ַ(CString����)ֱ����ʾ��IP Address�ؼ���

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWsnPcMonitorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWsnPcMonitorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWsnPcMonitorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

LONG CWsnPcMonitorDlg::OnComm(WPARAM ch, LPARAM port)
{
	//m_RcvMsg+=ch;
	//UpdateData(FALSE);

	BYTE receive = ch & 0x00ff;

	if(-1 == r_index)           //���ܵ���0xEF��Ϊ֡��ʼ��־
	{
		if(0xEF == receive)
		{
			dataReceive[0] = 0xEF;
			r_index = 1;
		}
		
	}
	else
	{
		if(r_index < 6)			//�м��ֽ�
		{
			dataReceive[r_index] = receive;
			r_index ++;
		}
		else					//ĩβ�ֽ� ��������Ƿ�ΪFE�����д���
		{
			dataReceive[r_index] = receive;
			r_index = -1;	//֡�������
			ReceiveDataAnalysis();
		}
	}


	return 0;
}

void CWsnPcMonitorDlg::OnBtnopen() 
{
	// TODO: Add your control notification handler code here
	int nPort = PortTab[m_ComSel.GetCurSel()];
	if (m_SerialPort.InitPort(this,nPort,38400,'N',8,1,EV_RXCHAR|EV_RXFLAG,512))
	{
		m_SerialPort.StartMonitoring();
		m_bSerialPortOpened = TRUE;
		m_PortLedStatu.SetActive(TRUE);

		m_EditText.Clear();
		m_EditText.SetWindowText("�򿪴��ڣ�ͨѶ������38400");

	} 
	else
	{
		AfxMessageBox("û�з��ִ˴��ڻ�ռ��");
		m_bSerialPortOpened=FALSE;
		m_PortLedStatu.SetActive(FALSE);

	}
	//��ť ���úͲ����� ���� 
	GetDlgItem(IDC_BTNOPEN)->EnableWindow(!m_bSerialPortOpened);
	GetDlgItem(IDC_BTNCLOSE)->EnableWindow(m_bSerialPortOpened);

	GetDlgItem(IDC_BTN_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTNAUTOUPLOAD)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	
	
}

void CWsnPcMonitorDlg::OnBtnClose() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);

	m_SerialPort.ClosePort();
	m_bSerialPortOpened = FALSE;
	m_PortLedStatu.SetActive(FALSE);
	//��ť ���úͲ����� ���� 
	GetDlgItem(IDC_BTNOPEN)->EnableWindow(!m_bSerialPortOpened);
	GetDlgItem(IDC_BTNCLOSE)->EnableWindow(m_bSerialPortOpened);

	GetDlgItem(IDC_BTN_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTNAUTOUPLOAD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);

	m_EditText.Clear();
	m_EditText.SetWindowText("�رմ���");
	
}

int CWsnPcMonitorDlg::GetSystemPorts(CString *pNameList, CString *pPortList)
{
	CRegKey RegKey;   
	int nCount = 0;   
	//��ע���
	if(RegKey.Open(HKEY_LOCAL_MACHINE, "Hardware\\DeviceMap\\SerialComm") == ERROR_SUCCESS)   
	{   
		while(true)   
		{   
			char ValueName[_MAX_PATH];   
			unsigned char ValueData[_MAX_PATH];   
			DWORD nValueSize = _MAX_PATH;   
			DWORD nDataSize = _MAX_PATH;   
			DWORD nType;   

			//ͨ��ö�ٻ�ȡ�������������������ֹ

			if(::RegEnumValue(HKEY(RegKey), nCount, ValueName, &nValueSize, NULL, &nType, ValueData, &nDataSize) == ERROR_NO_MORE_ITEMS)   
			{   
				break;   
			}   

		//������ҵ�һ��

		if(pNameList)   //����
			pNameList[nCount] = ValueName;   

		 if(pPortList)   //ֵ
			pPortList[nCount] = ValueData;   

			nCount++;   //����̽����һ��
		}   
	}   

	return nCount;

}

void CWsnPcMonitorDlg::OnBtnSend() 
{
	// TODO: Add your control notification handler code here
	if (m_bSerialPortOpened == TRUE)
	{
	
		m_EditText.Clear();
		m_EditText.SetWindowText("�ֶ�ˢ�»�ȡ����");

		BYTE SendBuf[6];
		
		//���¶�
		SendBuf[0] = 0xef;
		SendBuf[1] = 0xC0;
		SendBuf[2] = 0x00;
		SendBuf[3] = 0x00;
		SendBuf[4] = 0xC0;
		SendBuf[5] = 0xfe;
		
		m_SerialPort.WriteToPort((char*)SendBuf,6);		//����
		
		Sleep(100);
	} 
	else
	{
		MessageBox("���ȴ򿪴���!");
	}
	
}

BEGIN_EVENTSINK_MAP(CWsnPcMonitorDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CWsnPcMonitorDlg)
	ON_EVENT(CWsnPcMonitorDlg, IDC_ISWITCHROCKERX1, 1 /* OnChange */, OnOnChangeIswitchrockerx1, VTS_NONE)
	ON_EVENT(CWsnPcMonitorDlg, IDC_ISWITCHROCKERX1, 5 /* OnClick */, OnOnClickIswitchrockerx1, VTS_NONE)
	ON_EVENT(CWsnPcMonitorDlg, IDC_ISWITCHROCKERX2, 5 /* OnClick */, OnOnClickIswitchrockerx2, VTS_NONE)
	ON_EVENT(CWsnPcMonitorDlg, IDC_ISWITCHROCKERX3, 5 /* OnClick */, OnOnClickIswitchrockerx3, VTS_NONE)
	ON_EVENT(CWsnPcMonitorDlg, IDC_ISWITCHROCKERX4, 5 /* OnClick */, OnOnClickIswitchrockerx4, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CWsnPcMonitorDlg::OnOnChangeIswitchrockerx1() 
{
	// TODO: Add your control notification handler code here
	if (m_LedSwitch1.GetActive() == TRUE)
	{

	}
	else
	{
	
	}
	

}

BOOL CWsnPcMonitorDlg::CheckReceiveData()
{
	if(0xEF != dataReceive[0])
	{
		return FALSE;
	}
	if(0xFE != dataReceive[6])
	{
		return FALSE;
	}
	BYTE cs = dataReceive[1] + dataReceive[2] + dataReceive[3] + dataReceive[4];
	if( cs != dataReceive[5])
	{
		return FALSE;
	}
	return TRUE;

}

void CWsnPcMonitorDlg::ReceiveDataAnalysis()
{
// 	static int step = 0x00;
	int i=0;
	unsigned char Id;
	unsigned char temh,teml;//���ݸߵ��ֽ�
	

	if (CheckReceiveData())
	{
		Id = dataReceive[2];
		teml=dataReceive[3];
		temh=dataReceive[4];

		switch(dataReceive[1])
		{
		case 0x80: //���ּ��
			MessageBox("���ֳɹ���");
			
			break;

		case 0x81: //��ȡ�¶�
			//MessageBox("��ȡ�ɹ���");			
			
			unsigned char flag;
			char pChBuf[8];
			unsigned int num;	
			
		
			if(temh&0x80)//�ж�����
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}

			num=teml*625;          //С�����ֵ�ȡֵÿλ����0.0625�����ȣ�
			if(flag==1)            //�ж������¶�
			{
				pChBuf[0]='-';              //+0x2d Ϊ��"-"ASCII��
			}
			else 
				pChBuf[0]='+';   
			if(temh/100==0)
				pChBuf[1]=' ';
			else
				pChBuf[1]=temh/100+0x30;      //+0x30 Ϊ�� 0~9 ASCII��
			if((temh/10%10==0)&&(temh/100==0))
				pChBuf[2]=' ';
			else
				pChBuf[2]=temh/10%10+0x30;
			pChBuf[3]=temh%10+0x30;
			pChBuf[4]='.';
			pChBuf[5]=num/1000+0x30;//����С�����1λ����
			pChBuf[6]='\0';

			//��ʾ�¶���ֵ
			if (Id == 1)
			{
				m_temp1 = pChBuf;
			}else if (Id == 2)
			{
				m_temp2 = pChBuf;
			}else if (Id == 3)
			{
				m_temp3 = pChBuf;
			}else if (Id == 4)
			{
				m_temp4 = pChBuf;
			}
			
			UpdateData(FALSE);
			
			tempValueBuf[Id-1] = temh+num/10000;
			break;
		
		case 0x82: //��ȡ����
			//��ʾ������ֵ
			if (Id == 1)
			{
				m_Gas1 = teml;
			}else if (Id == 2)
			{
				m_Gas2 = teml;
			}else if (Id == 3)
			{
				m_Gas3 = teml;
			}else if (Id == 4)
			{
				m_Gas4 = teml;
			}
			
			
			UpdateData(FALSE);

			break;
		case 0x83: //��ȡ��ǿ
			
			//��ʾ��ǿ��ֵ
			if (Id == 1)
			{
				m_Light1Level = 220-teml;
			}else if (Id == 2)
			{
				m_Light2Level = 220-teml;
			}else if (Id == 3)
			{
				m_Light3Level = 220-teml;
			}else if (Id == 4)
			{
				m_Light4Level = 220-teml;
			}

			UpdateData(FALSE);

			break;
		case 0x84: //��ȡ��״̬
			if (Id == 1)
			{
				if (teml == 0)
				{
					m_LedSwitch1.SetActive(FALSE);
					LedOnOffFlag[0] = FALSE;
				} 
				else
				{
					m_LedSwitch1.SetActive(TRUE);
					LedOnOffFlag[0] = TRUE;
				}
			}else if (Id == 2)
			{
					if (teml == 0)
					{
						m_LedSwitch2.SetActive(FALSE);
						LedOnOffFlag[1] = FALSE;
					} 
					else
					{
						m_LedSwitch2.SetActive(TRUE);
						LedOnOffFlag[1] = TRUE;
				}
			}else if (Id == 3)
			{
				if (teml == 0)
				{
					m_LedSwitch3.SetActive(FALSE);
					LedOnOffFlag[2] = FALSE;
				} 
				else
				{
					m_LedSwitch3.SetActive(TRUE);
					LedOnOffFlag[2] = TRUE;
				}
			}else if (Id == 4)
			{
				if (teml == 0)
				{
					m_LedSwitch4.SetActive(FALSE);
					LedOnOffFlag[3] = FALSE;
				} 
				else
				{
					m_LedSwitch4.SetActive(TRUE);
					LedOnOffFlag[3] = TRUE;
				}
			}

			
			UpdateData(FALSE);

			break;
		case 0x85: //��ȡ����״̬
			if (Id == 1)
			{
				if (teml == 0)
				{
					m_Alarm1.SetActive(FALSE);
					AlarmFlag[0] = FALSE;
				} 
				else
				{
					m_Alarm1.SetActive(TRUE);
					AlarmFlag[0] = TRUE;
				}
			}else if (Id == 2)
			{
				if (teml == 0)
				{
					m_Alarm2.SetActive(FALSE);
					AlarmFlag[1] = FALSE;
				} 
				else
				{
					m_Alarm2.SetActive(TRUE);
					AlarmFlag[1] = TRUE;
				}
			}else if (Id == 3)
			{
				if (teml == 0)
				{
					m_Alarm3.SetActive(FALSE);
					AlarmFlag[2] = FALSE;
				} 
				else
				{
					m_Alarm3.SetActive(TRUE);
					AlarmFlag[2] = TRUE;
				}
			}else if (Id == 4)
			{
				if (teml == 0)
				{
					m_Alarm4.SetActive(FALSE);
					AlarmFlag[3] = FALSE;
				} 
				else
				{
					m_Alarm4.SetActive(TRUE);
					AlarmFlag[3] = TRUE;
				}

				//�ж��Ƿ�����������
				/*
				if (b_isSocketConnectFlag == TRUE)
				{
					sprintf(SendBuf, "LLLLL,%d,%d,%d,%d,", m_Light1Level,m_Light2Level,m_Light3Level,m_Light4Level);
				    Send(ClientSocket,SendBuf,50);
				}
				*/


			}
			
			
			UpdateData(FALSE);
			
			break;

		case 0x8F: //��ȡ�������

			//��ʾ�¶ȼ�				
			m_tempDisp1.SetPosition(tempValueBuf[0]);							
			m_tempDisp2.SetPosition(tempValueBuf[1]);							
			m_tempDisp3.SetPosition(tempValueBuf[2]);							
			m_tempDisp4.SetPosition(tempValueBuf[3]);				
						
			//��ʾ�¶�����
			if (m_SelectPlotIndex == 0)
			{
				m_plotx.GetChannel(0).AddYElapsedSeconds(tempValueBuf[0]);
				m_plotx.GetChannel(1).AddYElapsedSeconds(tempValueBuf[1]);
				m_plotx.GetChannel(2).AddYElapsedSeconds(tempValueBuf[2]);
				m_plotx.GetChannel(3).AddYElapsedSeconds(tempValueBuf[3]);
			} 
			else if (m_SelectPlotIndex == 1)
			{
				m_plotx.GetChannel(0).AddYElapsedSeconds(m_Light1Level);
				m_plotx.GetChannel(1).AddYElapsedSeconds(m_Light2Level);
				m_plotx.GetChannel(2).AddYElapsedSeconds(m_Light3Level);
				m_plotx.GetChannel(3).AddYElapsedSeconds(m_Light4Level);
			}
			else if (m_SelectPlotIndex == 2)
			{
				m_plotx.GetChannel(0).AddYElapsedSeconds(m_Gas1);
				m_plotx.GetChannel(1).AddYElapsedSeconds(m_Gas2);
				m_plotx.GetChannel(2).AddYElapsedSeconds(m_Gas3);
				m_plotx.GetChannel(3).AddYElapsedSeconds(m_Gas4);
			}
			
			

			

			break;
		}
	} 
	else //rcv is error
	{
	}

}

void CWsnPcMonitorDlg::OnBtnout() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	
}

void CWsnPcMonitorDlg::OnAutoFlash() 
{
	// TODO: Add your control notification handler code here
	m_EditText.Clear();
	m_EditText.SetWindowText("�����Զ�ˢ��");

	SetTimer(1,1000,NULL);	//������ʱ��2
	
}

void CWsnPcMonitorDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 1:
		{
			//KillTimer(1);
			
			BYTE SendBuf[6];
			
			//���¶�
			SendBuf[0] = 0xef;
			SendBuf[1] = 0xC0;
			SendBuf[2] = 0x00;
			SendBuf[3] = 0x00;
			SendBuf[4] = 0xC0;
			SendBuf[5] = 0xfe;
			
			m_SerialPort.WriteToPort((char*)SendBuf,6);		//����
			
		}
		break;
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CWsnPcMonitorDlg::OnOnClickIswitchrockerx1() 
{
	// TODO: Add your control notification handler code here
	if (m_bSerialPortOpened == TRUE)
	{
		//KillTimer(1);
		
		BYTE SendBuf[6];
		
		//���¶�
		SendBuf[0] = 0xef;
		SendBuf[1] = 0xC5;
		SendBuf[2] = 0x01;

		SendBuf[5] = 0xfe;
		
		if (m_LedSwitch1.GetActive() == TRUE)
		{
			SendBuf[3] = 0x00;
			SendBuf[4] = 0xC6;

			LedOnOffFlag[0] = 0;
		}
		else
		{
			SendBuf[3] = 0x01;
			SendBuf[4] = 0xC7;

			LedOnOffFlag[0] = 1;
		}
		
		
		m_SerialPort.WriteToPort((char*)SendBuf,6);		//����
		
		Sleep(250);

	} 
	else
	{
		MessageBox("���ȴ򿪴���!");
	}
}

void CWsnPcMonitorDlg::OnOnClickIswitchrockerx2() 
{
	// TODO: Add your control notification handler code here
	if (m_bSerialPortOpened == TRUE)
	{
	//KillTimer(1);
		
		BYTE SendBuf[6];
	
	//���¶�
	SendBuf[0] = 0xef;
	SendBuf[1] = 0xC5;
	SendBuf[2] = 0x02;

	SendBuf[5] = 0xfe;
	
	if (m_LedSwitch2.GetActive() == TRUE)
	{
		SendBuf[3] = 0x00;
		SendBuf[4] = 0xC7;

		LedOnOffFlag[1] = 0;
	}
	else
	{
		SendBuf[3] = 0x01;
		SendBuf[4] = 0xC8;

		LedOnOffFlag[1] = 1;
	}
	
	
	m_SerialPort.WriteToPort((char*)SendBuf,6);		//����
	
	Sleep(250);

} 
else
{
	MessageBox("���ȴ򿪴���!");
	}
}

void CWsnPcMonitorDlg::OnOnClickIswitchrockerx3() 
{
	// TODO: Add your control notification handler code here
	if (m_bSerialPortOpened == TRUE)
	{
	//KillTimer(1);
		
		BYTE SendBuf[6];
	
	//���¶�
	SendBuf[0] = 0xef;
	SendBuf[1] = 0xC5;
	SendBuf[2] = 0x03;
	SendBuf[5] = 0xfe;
	
	if (m_LedSwitch3.GetActive() == TRUE)
	{
		SendBuf[3] = 0x00;
		SendBuf[4] = 0xC8;

		LedOnOffFlag[2] = 0;
	}
	else
	{
		SendBuf[3] = 0x01;
		SendBuf[4] = 0xC9;

		LedOnOffFlag[2] = 1;
	}
	
	
	m_SerialPort.WriteToPort((char*)SendBuf,6);		//����
	
	Sleep(250);

} 
else
{
	MessageBox("���ȴ򿪴���!");
	}
}

void CWsnPcMonitorDlg::OnOnClickIswitchrockerx4() 
{
	// TODO: Add your control notification handler code here
	if (m_bSerialPortOpened == TRUE)
	{
	//KillTimer(1);
		
		BYTE SendBuf[6];
	
	//���¶�
	SendBuf[0] = 0xef;
	SendBuf[1] = 0xC5;
	SendBuf[2] = 0x04;
	SendBuf[5] = 0xfe;
	
	if (m_LedSwitch4.GetActive() == TRUE)
	{
		SendBuf[3] = 0x00;
		SendBuf[4] = 0xC9;

		LedOnOffFlag[3] = 0;
	}
	else
	{
		SendBuf[3] = 0x01;
		SendBuf[4] = 0xCA;

		LedOnOffFlag[3] = 1;
	}
	
	
	m_SerialPort.WriteToPort((char*)SendBuf,6);		//����
	
	Sleep(250);

} 
else
{
	MessageBox("���ȴ򿪴���!");
	}
}

void CWsnPcMonitorDlg::OnBtnStopFlash() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);

	m_EditText.Clear();
	m_EditText.SetWindowText("�ر��Զ�ˢ��");
	
}

void CWsnPcMonitorDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_SelectPlotIndex = 0;

	m_plotx.SetTitleText("�¶ȱ仯ͼ");

	m_plotx.RemoveAllChannels();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.GetChannel(0).SetTitleText("�ڵ�1");
	m_plotx.GetChannel(1).SetTitleText("�ڵ�2");
	m_plotx.GetChannel(2).SetTitleText("�ڵ�3");
	m_plotx.GetChannel(3).SetTitleText("�ڵ�4");

	//Re-Setup Axes
	m_plotx.GetYAxis(0).SetMin(0);
	m_plotx.GetYAxis(0).SetSpan(40);

	m_EditText.Clear();
	m_EditText.SetWindowText("�鿴�¶ȱ仯����");
	
}

void CWsnPcMonitorDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_SelectPlotIndex = 1;

	//Setup Chart
	m_plotx.SetTitleText("��ǿ�仯ͼ");
	//m_plotx.GetXAxis(0).SetMin(0);
	//m_plotx.GetXAxis(0).SetSpan(20/(60.0 * 60.0 * 24.0));
	//m_plotx.GetXAxis(0).SetLabelsFormatStyle(3); //iptfDateTime
	//m_plotx.GetXAxis(0).SetDateTimeFormat("nn:ss");
	//m_plotx.GetYAxis(0).SetMin(0);
	//m_plotx.GetYAxis(0).SetSpan(20);
	
	//Remove default channel
	
	m_plotx.RemoveAllChannels();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.GetChannel(0).SetTitleText("�ڵ�1");
	m_plotx.GetChannel(1).SetTitleText("�ڵ�2");
	m_plotx.GetChannel(2).SetTitleText("�ڵ�3");
	m_plotx.GetChannel(3).SetTitleText("�ڵ�4");

	m_plotx.GetYAxis(0).SetMin(0);
	m_plotx.GetYAxis(0).SetSpan(150);

	m_EditText.Clear();
	m_EditText.SetWindowText("�鿴��ǿ�仯����");
	
}

void CWsnPcMonitorDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	m_SelectPlotIndex = 2;

	m_plotx.SetTitleText("���庬���仯ͼ");

	m_plotx.RemoveAllChannels();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.AddChannel();
	m_plotx.GetChannel(0).SetTitleText("�ڵ�1");
	m_plotx.GetChannel(1).SetTitleText("�ڵ�2");
	m_plotx.GetChannel(2).SetTitleText("�ڵ�3");
	m_plotx.GetChannel(3).SetTitleText("�ڵ�4");

	m_plotx.GetYAxis(0).SetMin(0);
	m_plotx.GetYAxis(0).SetSpan(150);

	m_EditText.Clear();
	m_EditText.SetWindowText("�鿴��˹�����仯����");
	
}

void CWsnPcMonitorDlg::OnBtnStartListen() 
{
	// TODO: Add your control notification handler code here
	m_EditText.Clear();
	m_EditText.SetWindowText("���������������߳�");

	InitNetwork();

	m_SocketServerEnabled.SetActive(TRUE);
	
}

void CWsnPcMonitorDlg::OnBtnStopListen() 
{
	// TODO: Add your control notification handler code here
	m_EditText.Clear();
	m_EditText.SetWindowText("�رշ����������߳�");

	m_SocketServerEnabled.SetActive(FALSE);
	m_ClientLeds.SetPosition(0);

	OnClose(ServerSock);
	
}

void CWsnPcMonitorDlg::OnIPAddress()
{
	// �˶δ��룺�����Ļ�ȡ����IP��ַ�ͼ������
	
	WORD wVersionRequested;  
	WSADATA wsaData;  
	char name[255];  
 
	PHOSTENT hostinfo;  
	wVersionRequested = MAKEWORD(2,  0);  
    
	if  (WSAStartup(wVersionRequested, &wsaData) == 0)
	{  
		
		if(gethostname(name,  sizeof(name)) == 0)  
		{  
			if((hostinfo = gethostbyname(name)) != NULL)  
			{  
				IpAddr = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);  
			}  
		}    
		WSACleanup();  
	}
}

BOOL CWsnPcMonitorDlg::InitNetwork()
{
	
	WSADATA wsaData;	
	//��ʼ��TCPЭ��	
	BOOL ret = WSAStartup(MAKEWORD(2,2), &wsaData);	
	if(ret != 0)		
	{
		MessageBox("��ʼ������Э��ʧ��!");		
		return FALSE;		
	}
	
	//�������������׽���	
	ServerSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	
	if(ServerSock == INVALID_SOCKET)		
	{
		MessageBox("�����׽���ʧ��!");		
		closesocket(ServerSock);		
		WSACleanup();		
		return FALSE;		
	}
	
	//�󶨵�����һ���˿���	
	sockaddr_in localaddr;	
	localaddr.sin_family = AF_INET;	
	localaddr.sin_port = htons(DEFAULT_PORT);	//�˿ںŲ�Ҫ������Ӧ�ó����ͻ	
	localaddr.sin_addr.S_un.S_addr=INADDR_ANY;  //IP��ַ���ó�INADDR_ANY,��ϵͳ�Զ���ȡ������IP��ַ��
	
	if(bind(ServerSock ,(struct sockaddr*)&localaddr,sizeof(sockaddr)) == SOCKET_ERROR)		
	{		
		MessageBox("�󶨵�ַʧ��!");		
		closesocket(ServerSock);		
		WSACleanup();		
		return FALSE;		
	}
	
	//��SeverSock����Ϊ�첽������ģʽ����Ϊ��ע����������첽�¼����� �� m_hWnd	
	//ΪӦ�ó�������Ի���������ڵľ��	
	if(WSAAsyncSelect(ServerSock, m_hWnd, NETWORK_EVENT,
		FD_ACCEPT | FD_CLOSE | FD_READ | FD_WRITE) == SOCKET_ERROR)		
	{		
		MessageBox("ע�������첽�¼�ʧ��!");		
		WSACleanup();		
		return FALSE;		
	}	
	listen(ServerSock, 5);	//��������ģʽ
	
	return TRUE;	
}

void CWsnPcMonitorDlg::OnNetEvent(WPARAM wParam, LPARAM lParam)
{	
	//����Winsock API�������õ������¼�����
	int iEvent = WSAGETSELECTEVENT(lParam);
	//����Winsock API�������õ��������¼��Ŀͻ����׽���
	SOCKET CurSock= (SOCKET)wParam;
	ClientSocket = CurSock;
	switch(iEvent)
	{	
	case FD_ACCEPT: //�ͻ������������¼�	
		OnAccept(CurSock);	
		b_isSocketConnectFlag = TRUE;
		break;
		
	case FD_CLOSE: //�ͻ��˶Ͽ��¼�:	
		//OnClose(CurSock);
		
		//OnAccept(CurSock);

		b_isSocketConnectFlag = FALSE;
		m_ClientLeds.SetPosition(0);
		break;
		
	case FD_READ: //�������ݰ������¼�	
		OnReceive(CurSock);	
		break;
		
	default: break;	
	}

}

void CWsnPcMonitorDlg::OnAccept(SOCKET CurSock)
{	
//�����������󣬲������뷢����������Ŀͻ��˽���ͨ��Socket
//Ϊ�µ�socketע���첽�¼���ע��û��Accept�¼�
	char dispBuf[100];
	SOCKET ConnectSocket;
	sockaddr_in    ClientAddr;
	int	nLen = sizeof(sockaddr);
	//����ֱ���пͻ������ӣ���Ȼ���˷�CPU��Դ��
	ConnectSocket = accept(ServerSock,(sockaddr*)&ClientAddr,&nLen);
	//�õ��ͻ��˵�IP��ַ��
	char *pAddrname = inet_ntoa(ClientAddr.sin_addr);
	sprintf(dispBuf,"��¼:%s socketid=%d\n",pAddrname,ConnectSocket);
	m_EditText.SetWindowText(dispBuf);

	m_ClientLeds.SetPosition(100);
	 

}

void CWsnPcMonitorDlg::OnClose(SOCKET CurSock)
{	
//��������Ӧ�Ŀͻ��˵�ͨ�ţ��ͷ���Ӧ��Դ
	m_EditText.SetWindowText("�ͻ�����ͻ��������ѶϿ�...");

	closesocket(CurSock);
	WSACleanup();

}

void CWsnPcMonitorDlg::OnReceive(SOCKET CurSock)
{	
//�������绺�����е����ݰ�
	static cnt = 0;
	int n =recv(CurSock,szBuf,MAX_PATH,0);

	//��ͻ��˷��ͻ�Ӧ����
	if(n >= 5)
	{
	  switch(szBuf[2])
	  {
	  case 'T':
		  //Send(CurSock,"TTTTT,+12.7,+13.1,+12.6,+12.9,",30);
		  tmpSendString = "TTTTT,"+m_temp1+','+m_temp2+','+m_temp3+','+m_temp4+',';
		  strncpy(SendBuf,(LPCTSTR)tmpSendString,50); 
		  Send(CurSock,SendBuf,50);
		  break;
	  case 'L':
		  sprintf(SendBuf, "LLLLL,%d,%d,%d,%d,", m_Light1Level,m_Light2Level,m_Light3Level,m_Light4Level);
		  Send(CurSock,SendBuf,50);
		  break;
	  case 'G':
		  sprintf(SendBuf, "GGGGG,%8.2f,%8.2f,%8.2f,%8.2f,", m_Gas1,m_Gas2,m_Gas3,m_Gas4);
		  Send(CurSock,SendBuf,50);
		  //Send(CurSock,"GGGGG,55pp,66pp,45pp,35pp,",30);
		  break;
	  case 'A':
		  sprintf(SendBuf, "AAAAA,%d,%d,%d,%d,", AlarmFlag[0],AlarmFlag[1],AlarmFlag[2],AlarmFlag[3]);
		  Send(ClientSocket,SendBuf,50);
		  break;

	  case 'D':
		  if (szBuf[0] == '1')
		  {
			  if (szBuf[4] == '1')//����
			  {
				  if (m_LedSwitch1.GetActive() == FALSE)//�ٴ��жϵ��Ƿ�ر���-->��
				  {
					  OperateLed(0x01,1);//����
					  m_LedSwitch1.SetActive(TRUE);
					  LedOnOffFlag[0] = 1;
				  }
				  
			  } 
			  else//�ص�
			  {
				  if (m_LedSwitch1.GetActive() == TRUE)//�ٴ��жϵ��Ƿ���-->��
				  {
					  OperateLed(0x01,0);//�ص�
					  m_LedSwitch1.SetActive(FALSE);
					  LedOnOffFlag[0] = 0;
				  }
			  }
		  } 
		  else if(szBuf[0] == '2')
		  {
			  if (szBuf[4] == '1')//����
			  {
				  if (m_LedSwitch2.GetActive() == FALSE)//�ٴ��жϵ��Ƿ�ر���-->��
				  {
					  OperateLed(0x02,1);//����
					  m_LedSwitch2.SetActive(TRUE);
					  LedOnOffFlag[1] = 1;
				  }
				  
			  } 
			  else//�ص�
			  {
				  if (m_LedSwitch2.GetActive() == TRUE)//�ٴ��жϵ��Ƿ���-->��
				  {
					  OperateLed(0x02,0);//�ص�
					  m_LedSwitch2.SetActive(FALSE);
					  LedOnOffFlag[1] = 0;
				  }
			  }
		  }
		  else if(szBuf[0] == '3')
		  {
			  if (szBuf[4] == '1')//����
			  {
				  if (m_LedSwitch3.GetActive() == FALSE)//�ٴ��жϵ��Ƿ�ر���-->��
				  {
					  OperateLed(0x03,1);//����
					  m_LedSwitch3.SetActive(TRUE);
					  LedOnOffFlag[2] = 1;
				  }
				  
			  } 
			  else//�ص�
			  {
				  if (m_LedSwitch3.GetActive() == TRUE)//�ٴ��жϵ��Ƿ���-->��
				  {
					  OperateLed(0x03,0);//�ص�
					  m_LedSwitch3.SetActive(FALSE);
					  LedOnOffFlag[2] = 0;
				  }
			  }
		  }
		  else if(szBuf[0] == '4')
		  {
			  if (szBuf[4] == '1')//����
			  {
				  if (m_LedSwitch4.GetActive() == FALSE)//�ٴ��жϵ��Ƿ�ر���-->��
				  {
					  OperateLed(0x04,1);//����
					  m_LedSwitch4.SetActive(TRUE);
					  LedOnOffFlag[3] = 1;
				  }
				  
			  } 
			  else//�ص�
			  {
				  if (m_LedSwitch4.GetActive() == TRUE)//�ٴ��жϵ��Ƿ���-->��
				  {
					  OperateLed(0x04,0);//�ص�
					  m_LedSwitch4.SetActive(FALSE);
					  LedOnOffFlag[3] = 0;
				  }
			  }
		  }
		  else if(szBuf[0] == 'D')//��ѯ��״̬��������
		  {
			  		  
		  }
		  sprintf(SendBuf, "DDDDD,%d,%d,%d,%d,", LedOnOffFlag[0],LedOnOffFlag[1],LedOnOffFlag[2],LedOnOffFlag[3]);
		  Send(ClientSocket,SendBuf,50);
		  
		  break;
	  }		  
  
	}

	m_ClientLeds.SetPosition(cnt);
	cnt += 10;
	if (cnt >= 100)
	{
		cnt = 0;
	}

}

int CWsnPcMonitorDlg::Send(SOCKET fd, char *szText, int len)
{
	int cnt, rc;
	cnt=len;
	while(cnt>0)
	{
		rc=send(fd,szText,cnt,0);
		if(rc==SOCKET_ERROR)
		{
			return -1;
		}
		if(rc==0)
			return len-cnt;
		szText+=rc;
		cnt-=rc;
	}
	 
	return len;

}

void CWsnPcMonitorDlg::OperateLed(int ledID, BOOL staue)
{
	BYTE SendBuf[6];
	
	//���¶�
	SendBuf[0] = 0xef;
	SendBuf[1] = 0xC5;
	SendBuf[2] = ledID;
	SendBuf[3] = staue;
	SendBuf[4] = SendBuf[1]+SendBuf[2]+SendBuf[3];
	SendBuf[5] = 0xfe;

	m_SerialPort.WriteToPort((char*)SendBuf,6);		//����	
}
