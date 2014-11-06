#pragma once


// CTest dialog

class CTest : public CDialog
{
	DECLARE_DYNAMIC(CTest)

public:
	CTest(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTest();

// Dialog Data
	enum { IDD = IDD_VS2008X32_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
