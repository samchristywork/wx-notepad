#include "find.hpp"

void FindStrWindow::CancelClickCallback(wxCommandEvent &event) {
  this->Destroy();
}

void FindStrWindow::FindEnterCallback(wxCommandEvent &event) {
  this->FindNext();
}

void FindStrWindow::FindNextClickCallback(wxCommandEvent &event) {
  this->FindNext();
}

FindStrWindow::FindStrWindow(wxWindow *parent, wxTextCtrl *textCtrl)
    : FindFrame(parent) {
  this->Show(true);
  this->textCtrl = textCtrl;

  long from;
  long to;

  this->textCtrl->GetSelection(&from, &to);

  wxString value = this->textCtrl->GetValue();

  this->m_textCtrl3->SetValue(value.SubString(from, to));

  this->m_textCtrl3->SetSelection(0, -1);
}

void FindStrWindow::FindNext() {
  long from;
  long to;

  this->textCtrl->GetSelection(&from, &to);

  wxString value = this->textCtrl->GetValue();

  size_t pos = value.find(this->m_textCtrl3->GetValue(), from + 1);

  this->textCtrl->SetSelection(pos,
                               pos + this->m_textCtrl3->GetValue().length());
}

