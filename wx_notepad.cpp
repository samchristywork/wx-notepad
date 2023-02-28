#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "codegen/noname.h"
#include <string>
#include <wx/filedlg.h>
#include <wx/menu.h>
#include <wx/textfile.h>

enum {
  ID_Exit,
  ID_New,
  ID_New_Window,
  ID_Open,
  ID_Save,
  ID_Save_As,
};

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
    this->Show(true);

    wxMenuBar *menuBar = new wxMenuBar(0);

    wxMenu *menuFile = new wxMenu();

    add_menu_item(menuFile, wxString(wxT("New")), ID_New);
    add_menu_item(menuFile, wxString(wxT("New Window")), ID_New_Window);
    add_menu_item(menuFile, wxString(wxT("Open...\tCtrl-O")), ID_Open);
    add_menu_item(menuFile, wxString(wxT("Save")), ID_Save);
    add_menu_item(menuFile, wxString(wxT("Save As...")), ID_Save_As);
    menuFile->AppendSeparator();
    add_menu_item(menuFile, wxString(wxT("Exit")), ID_Exit);

    menuBar->Append(menuFile, wxT("File"));

    this->SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &Frame::New, this, ID_New);
    Bind(wxEVT_MENU, &Frame::NewWindow, this, ID_New_Window);
    Bind(wxEVT_MENU, &Frame::Open, this, ID_Open);
    Bind(wxEVT_MENU, &Frame::Save, this, ID_Save);
    Bind(wxEVT_MENU, &Frame::SaveAs, this, ID_Save_As);
    Bind(wxEVT_MENU, &Frame::Exit, this, ID_Exit);

  void New(wxCommandEvent &event) {}

  void NewWindow(wxCommandEvent &event) {}

  void Open(wxCommandEvent &event) {
  }

  void Save(wxCommandEvent &event) {}

  void SaveAs(wxCommandEvent &event) {}

  void Exit(wxCommandEvent &event) { this->Destroy(); }

  }
};

bool App::OnInit() {
  new Frame(NULL);
  return true;
}

wxIMPLEMENT_APP(App);
