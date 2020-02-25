// dllmain.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE DuiPluginsDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// ���ʹ�� lpReserved���뽫���Ƴ�
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("DuiPlugins.DLL ���ڳ�ʼ��!\n");
		
		// ��չ DLL һ���Գ�ʼ��
		if (!AfxInitExtensionModule(DuiPluginsDLL, hInstance))
			return 0;

		// ���� DLL ���뵽��Դ����
		// ע��: �������չ DLL ��
		//  MFC ���� DLL (�� ActiveX �ؼ�)��ʽ���ӵ���
		//  �������� MFC Ӧ�ó������ӵ�������Ҫ
		//  �����д� DllMain ���Ƴ������������һ��
		//  �Ӵ���չ DLL �����ĵ����ĺ����С�ʹ�ô���չ DLL ��
		//  ���� DLL Ȼ��Ӧ��ʽ
		//  ���øú����Գ�ʼ������չ DLL������
		//  CDynLinkLibrary ���󲻻ḽ�ӵ�
		//  ���� DLL ����Դ���������������ص�
		//  ���⡣

		new CDynLinkLibrary(DuiPluginsDLL);

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("DuiPlugins.DLL ������ֹ!\n");

		// �ڵ�����������֮ǰ��ֹ�ÿ�
		AfxTermExtensionModule(DuiPluginsDLL);
	}
	return 1;   // ȷ��
}

#include "GridCtrlUI.h"
#include "MsgWndUI.h"
#include "KeyBoardUI.h"
#include "KeyBoardNumberUI.h"
#include "KeyBoardSimpleUI.h"
#include "ImageBoxUI.h"
#include "PictureControlUI.h"

extern "C" __declspec(dllexport) void DuiPluginsRegister()
{
	REGIST_DUICONTROL(CGridCtrlUI);
	REGIST_DUICONTROL(CMsgWndUI);
	REGIST_DUICONTROL(CKeyBoardUI);
	REGIST_DUICONTROL(CKeyBoardNumberUI);
	REGIST_DUICONTROL(CKeyBoardSimpleUI);
	REGIST_DUICONTROL(CImageBoxUI);
	REGIST_DUICONTROL(CPictureControlUI);
}

extern "C" __declspec(dllexport) CControlUI *CreateControl(LPCTSTR pstrClass)
{
	if( _tcscmp(pstrClass, _T("GridCtrl")) == 0 ) 
	{
		return new CGridCtrlUI;
	}
	else if( _tcscmp(pstrClass, _T("MsgWnd")) == 0 ) 
	{
		return new CMsgWndUI;
	}
	else if( _tcscmp(pstrClass, _T("KeyBoard")) == 0 ) 
	{
		return new CKeyBoardUI;
	}
	else if( _tcscmp(pstrClass, _T("KeyBoardNumber")) == 0 ) 
	{
		return new CKeyBoardNumberUI;
	}
	else if( _tcscmp(pstrClass, _T("KeyBoardSimple")) == 0 ) 
	{
		return new CKeyBoardSimpleUI;
	}
	else if( _tcscmp(pstrClass, _T("ImageBox")) == 0 ) 
	{
		return new CImageBoxUI;
	}
	else if( _tcscmp(pstrClass, _T("PictureControl")) == 0 ) 
	{
		return new CPictureControlUI;
	}
	return NULL;
}

extern "C" __declspec(dllexport) void InsertMsgUI(LPCTSTR pstring, COLORREF cr)
{
	CMsgWndUI::InsertMsg(pstring, cr);
}