
// ETExplorerView.h : interface of the CETExplorerView class
//

#pragma once
#include <afxshelllistctrl.h>


class CETExplorerView : public CView
{
protected: // create from serialization only
	CETExplorerView();
	DECLARE_DYNCREATE(CETExplorerView)

// Attributes
public:
	CETExplorerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CETExplorerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
// Generated message map functions
private:
	CMFCShellListCtrl m_wndList;
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in ETExplorerView.cpp
inline CETExplorerDoc* CETExplorerView::GetDocument() const
   { return reinterpret_cast<CETExplorerDoc*>(m_pDocument); }
#endif

