#pragma once


// CDlgInsertControl �Ի���

class CDlgInsertControl : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgInsertControl)

public:
	CDlgInsertControl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgInsertControl();

// �Ի�������
	enum { IDD = IDD_DLG_INSERT_CONTROL };

	int m_nPosition;
	xml_node nodeParent;	//���ؼ�
	xml_node nodeControl;		//��ǰѡ�еĿؼ�
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};