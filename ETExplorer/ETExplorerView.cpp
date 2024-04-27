
// ETExplorerView.cpp : implementation of the CETExplorerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ETExplorer.h"
#endif

#include "ETExplorerDoc.h"
#include "ETExplorerView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CETExplorerView

IMPLEMENT_DYNCREATE(CETExplorerView, CView)

BEGIN_MESSAGE_MAP(CETExplorerView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CETExplorerView construction/destruction

CETExplorerView::CETExplorerView()
{
	// TODO: add construction code here

}

CETExplorerView::~CETExplorerView()
{
}

BOOL CETExplorerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CETExplorerView drawing

void CETExplorerView::OnDraw(CDC* /*pDC*/)
{
	CETExplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CETExplorerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CETExplorerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CETExplorerView diagnostics

#ifdef _DEBUG
void CETExplorerView::AssertValid() const
{
	CView::AssertValid();
}

void CETExplorerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CETExplorerDoc* CETExplorerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CETExplorerDoc)));
	return (CETExplorerDoc*)m_pDocument;
}
#endif //_DEBUG


// CETExplorerView message handlers


int CETExplorerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect rectDummy(0, 0, 0, 0);
	m_wndList.Create(WS_CHILD | WS_VISIBLE | LVS_REPORT, rectDummy, this, 1);
	return 0;
}


void CETExplorerView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_wndList.SetWindowPos(NULL, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
}

void CETExplorerView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	if (bActivate&&AfxGetMainWnd()!=NULL)
	{
		((CMainFrame*)AfxGetMainWnd())->GetShellTreeCtrl().SetRelatedList(&m_wndList);
	}
	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}