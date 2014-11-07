// VS2008x32Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "VS2008x32.h"
#include "VS2008x32Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BOOL FileExists(CString sFile)
{
	bool bExists = false;
	FILE* fp = fopen(sFile.GetBuffer(0), "rb");
	if (fp) {
		// file exists, try again
		bExists = true;
		fclose(fp);
	}
	return bExists;
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////


CVS2008x32Dlg::CVS2008x32Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVS2008x32Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVS2008x32Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, lb);
}

BEGIN_MESSAGE_MAP(CVS2008x32Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CVS2008x32Dlg::OnLoad)
	ON_BN_CLICKED(IDC_BUTTON2, &CVS2008x32Dlg::OnSave)
END_MESSAGE_MAP()


// CVS2008x32Dlg message handlers

BOOL CVS2008x32Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	Filename = "\\CZ Test Projects\\Data\\Data.bin";

	Populate();
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CVS2008x32Dlg::LoadData()
{

	// Load \CZ Test Projects\Data\Data.bin or create and save;
	if (FileExists(Filename)) {
		// found read it
		FILE* fp = fopen(Filename.GetBuffer(0), "rb");
		if (fp) {

			int size = sizeof(settings.Data);
			memset(&settings.Data, 0, size);
			fread(&settings.Data,size,1,fp);
		
			fclose(fp);
		}
	} else {
		// not found save it
		OnSave();
	}

}

CString Format2(CString format, CString s1, CString s2)
{
	CString str;
	str.Format(format, s1, s2);
	return str;
}

void CVS2008x32Dlg::Populate()
{
	int size = sizeof(settings.Data);
	memset(&settings.Data, 0, size);

	LoadData();

	CString str;
	str.Format("BYTE: %i", settings.Data.b);
	lb.AddString(str);

	str.Format("int: %d", settings.Data.i);
	lb.AddString(str);

	str.Format("char: %c", settings.Data.c);
	lb.AddString(str);

	str.Format("char[32]: %s", settings.Data.str);
	lb.AddString(str);

	str.Format("float: %1.2f", settings.Data.f);
	lb.AddString(str);

	str.Format("double: %1.2lf", settings.Data.d);
	lb.AddString(str);

	str.Format("bool: %i", (int)settings.Data.tf);
	lb.AddString(str);

	str.Format("long: %i", settings.Data.l);
	lb.AddString(str);

}

void CVS2008x32Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialog::OnSysCommand(nID, lParam);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVS2008x32Dlg::OnPaint()
{
	CDialog::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVS2008x32Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVS2008x32Dlg::OnLoad()
{
	// Load
	// load \Data32.bin
}

void CVS2008x32Dlg::OnSave()
{
	// Save
	FILE* fp = fopen(Filename.GetBuffer(0), "wb");
	if (fp) {

		int size = sizeof(settings.Data);
		fwrite(&settings.Data,size,1,fp);
	
		fclose(fp);
	}
	//Last comment - Mark
}
