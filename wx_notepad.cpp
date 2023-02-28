#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class App : public wxApp {
public:
  virtual bool OnInit();
};

void add_menu_item(wxMenu *menu, wxString text, int id) {
  wxMenuItem *menuItem =
      new wxMenuItem(menu, id, text, wxEmptyString, wxITEM_NORMAL);

  menu->Append(menuItem);
}

class Frame : public MainFrame {
public:
  Frame(wxWindow *parent) : MainFrame(parent) {

    wxMenuBar *menuBar = new wxMenuBar(0);

    wxMenu *menuFile = new wxMenu();

    add_menu_item(menuFile, wxString(wxT("Exit")), ID_Exit);

    menuBar->Append(menuFile, wxT("File"));

    this->SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &Frame::Exit, this, ID_Exit);
  }

  void Exit(wxCommandEvent &event) { this->Destroy(); }

  }
};

bool App::OnInit() {
  Frame *frame = new Frame(NULL);
  frame->Show(true);
  return true;
}

wxIMPLEMENT_APP(App);
