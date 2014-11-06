// Test.cpp : implementation file
//

#include "stdafx.h"
#include "VS2008x32.h"
#include "Test.h"


// CTest dialog

IMPLEMENT_DYNAMIC(CTest, CDialog)

CTest::CTest(CWnd* pParent /*=NULL*/)
	: CDialog(CTest::IDD, pParent)
{

}

CTest::~CTest()
{
}

void CTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTest, CDialog)
END_MESSAGE_MAP()


// CTest message handlers
