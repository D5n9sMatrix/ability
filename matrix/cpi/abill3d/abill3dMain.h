/***************************************************************
 * Name:      abill3dMain.h
 * Purpose:   Defines Application Frame
 * Author:    D5n9sMatrix (denis.02live@hotmail.com)
 * Created:   2022-01-11
 * Copyright: D5n9sMatrix (https://www.bing.com/?FORM=Z9FD1)
 * License:
 **************************************************************/

#ifndef ABILL3DMAIN_H
#define ABILL3DMAIN_H



#include "abill3dApp.h"



#include "GUIDialog.h"
#ifdef ABILL3Dialog
class abill3dDialog: public GUIDialog
{
    public:
        abill3dDialog(wxDialog *dlg);
        ~abill3dDialog();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};
#endif // ABILL3DMAIN_H
#endif // ABILL3Dialog
