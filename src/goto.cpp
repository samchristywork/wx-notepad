#include <wx/valnum.h>

#include "goto.hpp"

void GoToWindow::GoToClickCallback(wxCommandEvent &event) {
  wxString str = this->m_textCtrl2->GetValue();

  int number = wxAtoi(str);

  long pos = this->textCtrl->XYToPosition(0, number - 1);

  this->textCtrl->SetInsertionPoint(pos);
  this->Destroy();
}

void GoToWindow::GoToCancelCallback(wxCommandEvent &event) { this->Destroy(); }

void GoToWindow::GoToLineEnterCallback(wxCommandEvent &event) {
  wxString str = this->m_textCtrl2->GetValue();

  int number = wxAtoi(str);

  long pos = this->textCtrl->XYToPosition(0, number - 1);

  this->textCtrl->SetInsertionPoint(pos);
  this->Destroy();
}

GoToWindow::GoToWindow(wxWindow *parent, wxTextCtrl *textCtrl)
    : GoToFrame(parent) {
  this->Show(true);

  this->textCtrl = textCtrl;

  unsigned long m_value;
  wxIntegerValidator<unsigned long> validator(&m_value,
                                              wxNUM_VAL_THOUSANDS_SEPARATOR);

  this->m_textCtrl2->SetValidator(validator);

  int position = textCtrl->GetInsertionPoint();

  long x = 0;
  long y = 0;
  textCtrl->PositionToXY(position, &x, &y);

  x++;
  y++;

  int n = y;

  this->m_textCtrl2->SetValue(std::to_string(n));

  this->m_textCtrl2->SetSelection(0, -1);
}
