#ifndef GOTO_H
#define GOTO_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <string>
#include <wx/config.h>
#include <wx/filedlg.h>
#include <wx/menu.h>
#include <wx/mimetype.h>
#include <wx/stc/stc.h>
#include <wx/textfile.h>
#include <wx/valnum.h>

class GoToWindow : public GoToFrame {
public:
  wxTextCtrl *textCtrl;

  GoToWindow(wxWindow *parent, wxTextCtrl *textCtrl);
  virtual void GoToClickCallback(wxCommandEvent &event);
  virtual void GoToCancelCallback(wxCommandEvent &event);
  virtual void GoToLineEnterCallback(wxCommandEvent &event);
};

#endif
