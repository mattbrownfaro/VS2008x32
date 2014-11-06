// VS2008x32.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CVS2008x32App:
// See VS2008x32.cpp for the implementation of this class
//


class CVS2008x32App : public CWinApp
{
public:

public:
	CVS2008x32App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CVS2008x32App theApp;