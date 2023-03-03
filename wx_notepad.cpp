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
  wxString filename = "";
  wxTextFileType fileType;
  wxString zoomLevel = "100%";
  wxString textEncoding = "UTF-8";

  Frame(wxWindow *parent) : MainFrame(parent) {
    this->Show(true);

    this->UpdateTitle();

    wxMenuBar *menuBar = new wxMenuBar(0);

    wxMenu *menuFile = new wxMenu();

    add_menu_item(menuFile, wxString(wxT("New\tCtrl+N")), ID_New);
    add_menu_item(menuFile, wxString(wxT("New Window\tCtrl+Shift+N")),
                  ID_New_Window);
    add_menu_item(menuFile, wxString(wxT("Open...\tCtrl-O")), ID_Open);
    add_menu_item(menuFile, wxString(wxT("Save\tCtrl-S")), ID_Save);
    add_menu_item(menuFile, wxString(wxT("Save As...\tCtrl+Shift+S")),
                  ID_Save_As);
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

    this->RedrawStatusBar();
  }

  void UpdateTitle() {
    wxString title = "";

    if (this->m_textCtrl->IsModified()) {
      title += "*";
    }

    if (this->filename == "") {
      title += "Untitled - wxNotepad";
      this->SetTitle(title);
    } else {

      title += this->filename + " - wxNotepad";
      this->SetTitle(title);
    }
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

    wxString filename = openFileDialog.GetPath();
    this->LoadFile(filename);
  }

  void Save(wxCommandEvent &event) {
    wxString text = this->m_textCtrl->GetValue();

    if (this->filename == "") {
      wxFileDialog dialog(this, "Save .txt file...", "", "",
                          "All files (*.*)|*.* | Text files (*.txt) | *.txt",
                          wxFD_SAVE);
      if (dialog.ShowModal() == wxID_OK) {
        wxFile file(dialog.GetPath(), wxFile::write);
        if (file.IsOpened()) {
          file.Write(text);
          file.Close();
          this->m_textCtrl->SetModified(false);
        }
      }
    } else {
      wxFile file(this->filename, wxFile::write);
      if (file.IsOpened()) {
        file.Write(text);
        file.Close();
        this->m_textCtrl->SetModified(false);
      }
    }
    this->UpdateTitle();
    return;
  }

  void SaveAs(wxCommandEvent &event) {
    wxString text = this->m_textCtrl->GetValue();

    wxFileDialog dialog(this, "Save .txt file...", "", "",
                        "All files (*.*)|*.* | Text files (*.txt) | *.txt",
                        wxFD_SAVE);
    if (dialog.ShowModal() == wxID_OK) {
      wxFile file(dialog.GetPath(), wxFile::write);
      if (file.IsOpened()) {
        file.Write(text);
        file.Close();
        this->filename=dialog.GetPath();
        this->m_textCtrl->SetModified(false);
      }
    }
    this->UpdateTitle();

    return;
  }

  void Exit(wxCommandEvent &event) { this->Destroy(); }

  void ManualLoadFile(wxString filename) {
    FILE *f = fopen(filename, "rb");

    fseek(f, 0L, SEEK_END);
    size_t len = ftell(f);
    rewind(f);

    char buf[len + 1];
    fread(buf, 1, len, f);
    fclose(f);

    buf[len] = 0;

    this->m_textCtrl->WriteText(buf);
  }

  void LoadFileWithLineEndings(wxString filename) {
    wxTextFile tfile;
    tfile.Open(filename);
    this->fileType = tfile.GuessType();

    wxString text = tfile.GetFirstLine();
    this->m_textCtrl->SetValue(text);

    while (!tfile.Eof()) {
      text = tfile.GetNextLine();
      switch (this->fileType) {
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

    tfile.Close();
  }

  void LoadFile(wxString filename) {
    wxTextFile tfile;
    tfile.Open(filename);
    this->fileType = tfile.GuessType();
    tfile.Close();

    this->filename = filename;
    this->m_textCtrl->LoadFile(filename);
    this->m_textCtrl->SetInsertionPoint(0);
    this->UpdateTitle();
  }

  void UpdateUICallback(wxUpdateUIEvent &event) {
    this->RedrawStatusBar();

    event.Skip();
  }

  void RedrawStatusBar() {
    std::string str = "";
    int position = this->m_textCtrl->GetInsertionPoint();

    long x = 0;
    long y = 0;
    this->m_textCtrl->PositionToXY(position, &x, &y);

    x++;
    y++;

    str += "Ln ";
    str += std::to_string(x);
    str += ", Col ";
    str += std::to_string(y);

    this->m_statusBar->SetStatusText(str, 1);

    this->m_statusBar->SetStatusText(this->zoomLevel, 2);

    switch (this->fileType) {
    case wxTextFileType_Unix: {
      this->m_statusBar->SetStatusText("Unix (LF)", 3);
      break;
    }
    case wxTextFileType_Dos: {
      this->m_statusBar->SetStatusText("Windows (CRLF)", 3);
      break;
    }
    case wxTextFileType_Mac: {
      this->m_statusBar->SetStatusText("Mac (CR)", 3);
      break;
    }
    case wxTextFileType_Os2: {
      this->m_statusBar->SetStatusText("OS2 (LFCR)", 3);
      break;
    }
    default: {
      break;
    }
    }

    this->m_statusBar->SetStatusText(this->textEncoding, 4);

    this->UpdateTitle();
  }
};

bool App::OnInit() {
  if (wxApp::argc == 1) {
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
