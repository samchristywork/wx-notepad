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
    add_menu_item(menuFile, wxString(wxT("Save\tCtrl-S")), ID_Save);
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

    int widths[] = {-1, 100, 100, 100, 100};
    this->m_statusBar->SetFieldsCount(5, widths);
  }

  void New(wxCommandEvent &event) { this->m_textCtrl->SetValue(""); }

  void NewWindow(wxCommandEvent &event) { new Frame(NULL); }

  void Open(wxCommandEvent &event) {
    wxFileDialog openFileDialog(
        this, _("Open file"), "", "",
        "All files|*|Text files (*.txt;*.tx)|*.txt;*.tx",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL) {
      return;
    }

    this->LoadFile(openFileDialog.GetPath());
    wxTextFile tfile;
    tfile.Open(filename);
    wxTextFileType fileType = tfile.GuessType();

    wxString text = tfile.GetFirstLine();
    this->m_textCtrl->SetValue(text);

    while (!tfile.Eof()) {
      text = tfile.GetNextLine();
      switch (fileType) {
      case wxTextFileType_Unix: {
        this->m_textCtrl->AppendText("\n");
        break;
      }
      case wxTextFileType_Dos: {
        this->m_textCtrl->AppendText("\r\n");
        break;
      }
      case wxTextFileType_Mac: {
        this->m_textCtrl->AppendText("\r");
        break;
      }
      case wxTextFileType_Os2: {
        this->m_textCtrl->AppendText("\r\n");
        break;
      }
      default: {
        break;
      }
      }
      this->m_textCtrl->AppendText(text);
    }
  }

  void Save(wxCommandEvent &event) {}

  void SaveAs(wxCommandEvent &event) {}

  void Exit(wxCommandEvent &event) { this->Destroy(); }

  void TextCallback(wxCommandEvent &event) {
    std::string str = "";
    str += std::to_string(strlen(this->m_textCtrl->GetValue()));
    this->m_statusBar->SetStatusText(str, 1);
  }
};

bool App::OnInit() {
  if (wxApp::argc==1) {
    new Frame(NULL);
    return true;
  }

  for (int i = 1; i < wxApp::argc; i++) {
    puts(wxApp::argv[i]);
    Frame *f = new Frame(NULL);
    f->LoadFile(wxApp::argv[i]);
  }

  return true;
}

wxIMPLEMENT_APP(App);
