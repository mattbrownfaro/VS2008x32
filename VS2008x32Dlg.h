// VS2008x32Dlg.h : header file
//

#pragma once
#include "afxwin.h"

class Settings {
public:
	struct DataStruct {
		BYTE b;
		int i;
		char c;
		wchar_t str[32];
		float f;
		double d;
		bool tf;
		long l;
	} Data;      

	Settings() {
		Data.b = 1;
		Data.i = 2;
		Data.c = '3';
		wcscpy(Data.str, L"test string");
		//strcpy(Data.str, "test string");
		Data.f = 4.0;
		Data.d = 5.0;
		Data.tf = false;
		Data.l = 6;
	};
};

// CVS2008x32Dlg dialog
class CVS2008x32Dlg : public CDialog
{
// Construction
public:
	CVS2008x32Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_VS2008X32_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	Settings settings;
	CString Filename;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox lb;
	afx_msg void OnLoad();
	afx_msg void OnSave();

	void LoadData();
	void Populate();

};
