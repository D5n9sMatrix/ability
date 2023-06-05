/***************************************************************
 * Name:      abill3dMain.cpp
 * Purpose:   Code for Application Frame
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

#include "abill3dMain.h"
#if ABILL3DMAIN_HELP
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}



abill3dDialog::abill3dDialog(wxDialog *dlg)
    : GUIDialog(dlg)
{
}

abill3dDialog::~abill3dDialog()
{
}

void abill3dDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void abill3dDialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void abill3dDialog::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
#endif // ABILL3DMAIN_HELP
