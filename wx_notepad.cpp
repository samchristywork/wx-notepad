#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class App : public wxApp {
public:
  virtual bool OnInit();
};

class Frame : public MainFrame {
public:
  Frame(wxWindow *parent) : MainFrame(parent) {}
  void hello_world(wxCommandEvent &event) {
    puts("hi");
  }
};

bool App::OnInit() {
  Frame *frame = new Frame(NULL);
  frame->Show(true);
  return true;
}

wxIMPLEMENT_APP(App);
