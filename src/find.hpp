#ifndef FIND_H
#define FIND_H

#include "../codegen/noname.h"

class FindStrWindow : public FindFrame {
public:
  wxTextCtrl *textCtrl;

  FindStrWindow(wxWindow *parent, wxTextCtrl *textCtrl);
  void FindNext();

  virtual void FindNextClickCallback(wxCommandEvent &event);
  virtual void CancelClickCallback(wxCommandEvent &event);
  virtual void FindEnterCallback(wxCommandEvent &event);
};

#endif
