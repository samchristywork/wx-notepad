#ifndef GOTO_H
#define GOTO_H

#include "../codegen/noname.h"

class GoToWindow : public GoToFrame {
public:
  wxTextCtrl *textCtrl;

  GoToWindow(wxWindow *parent, wxTextCtrl *textCtrl);

private:
  virtual void GoToCancelCallback(wxCommandEvent &event);
  virtual void GoToClickCallback(wxCommandEvent &event);
  virtual void GoToLineEnterCallback(wxCommandEvent &event);
};

#endif
