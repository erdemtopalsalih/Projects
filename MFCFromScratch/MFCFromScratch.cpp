/*--------------------------------------------------------------------------------------------------------------------------------
MFC Application from Scratch - (c) 2023, Erdem Topalsalih.
--------------------------------------------------------------------------------------------------------------------------------*/
//MFCFromScratch.cpp - Implementation file for the CMFCFromScratch class, which represents the application object.
#include <afxwin.h>
#include "MFCFromScratch.h"
#include "mainfrm.h"

CMFCFromScratch MFCFromScratch;

CMFCFromScratch::CMFCFromScratch()
{
}

BOOL CMFCFromScratch::InitInstance()
{
	m_pMainWnd=new CMainFrame();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	return TRUE;
}