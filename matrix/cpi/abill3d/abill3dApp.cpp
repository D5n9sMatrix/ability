/***************************************************************
 * Name:      abill3dApp.cpp
 * Purpose:   Code for Application Class
 * Author:    D5n9sMatrix (denis.02live@hotmail.com)
 * Created:   2022-01-11
 * Copyright: D5n9sMatrix (https://www.bing.com/?FORM=Z9FD1)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "abill3dApp.h"
#include "abill3dMain.h"
#ifdef ABILL3DAPPMain
IMPLEMENT_APP(abill3dApp);

bool abill3dApp::OnInit()
{

    abill3dDialog* dlg = new abill3dDialog(0L);

    dlg->Show();
    return true;
}
#endif // ABILL3DAPPMain
