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

#include "codegen/noname.h"

enum {
  ID_Exit,
  ID_New,
  ID_New_Window,
  ID_Open,
  ID_Save,
  ID_Save_As,
  ID_Undo,
  ID_Cut,
  ID_Copy,
  ID_Paste,
  ID_Delete,
  ID_Find,
  ID_FindNext,
  ID_FindPrevious,
  ID_Replace,
  ID_GoTo,
  ID_SelectAll,
  ID_TimeDate,
  ID_WordWrap,
  ID_Font,
  ID_StatusBar,
  ID_ZoomIn,
  ID_ZoomOut,
  ID_RestoreDefaultZoom,
  ID_ViewHelp,
  ID_SendFeedback,
  ID_AboutNotepad,
};

class App : public wxApp {
public:
  virtual bool OnInit();
};

class FindStrWindow : public FindFrame {
public:
  wxTextCtrl *textCtrl;

  FindStrWindow(wxWindow *parent, wxTextCtrl *textCtrl);
  void FindNext();

  virtual void FindNextClickCallback(wxCommandEvent &event);
  virtual void CancelClickCallback(wxCommandEvent &event);
  virtual void FindEnterCallback(wxCommandEvent &event);
};

class GoToWindow : public GoToFrame {
public:
  wxTextCtrl *textCtrl;

  GoToWindow(wxWindow *parent, wxTextCtrl *textCtrl);
  virtual void GoToClickCallback(wxCommandEvent &event);
  virtual void GoToCancelCallback(wxCommandEvent &event);
  virtual void GoToLineEnterCallback(wxCommandEvent &event);
};

void add_menu_item(wxMenu *menu, wxString text, int id) {
  wxMenuItem *menuItem =
      new wxMenuItem(menu, id, text, wxEmptyString, wxITEM_NORMAL);

  menu->Append(menuItem);
}

// TODO Make things private

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

class Frame : public MainFrame {
public:
  wxString filename = "";
  wxTextFileType fileType;
  int zoomLevel = 100;
  wxString textEncoding = "UTF-8";

  Frame(wxWindow *parent) : MainFrame(parent) {
    this->Show(true);

    this->UpdateTitle();

    wxMenuBar *menuBar = new wxMenuBar(0);

    wxMenu *menuFile = new wxMenu();
    wxMenu *menuEdit = new wxMenu();
    wxMenu *menuFormat = new wxMenu();
    wxMenu *menuView = new wxMenu();
    wxMenu *menuHelp = new wxMenu();
    wxMenu *menuZoom = new wxMenu();

    add_menu_item(menuFile, wxString(wxT("New\tCtrl+N")), ID_New);
    add_menu_item(menuFile, wxString(wxT("New Window\tCtrl+Shift+N")),
                  ID_New_Window);
    add_menu_item(menuFile, wxString(wxT("Open...\tCtrl-O")), ID_Open);
    add_menu_item(menuFile, wxString(wxT("Save\tCtrl-S")), ID_Save);
    add_menu_item(menuFile, wxString(wxT("Save As...\tCtrl+Shift+S")),
                  ID_Save_As);
    menuFile->AppendSeparator();
    add_menu_item(menuFile, wxString(wxT("Exit")), ID_Exit);

    add_menu_item(menuEdit, wxString(wxT("Undo\tCtrl+Z")), ID_Undo);
    menuEdit->AppendSeparator();
    add_menu_item(menuEdit, wxString(wxT("Cut\tCtrl+X")), ID_Cut);
    add_menu_item(menuEdit, wxString(wxT("Copy\tCtrl+C")), ID_Copy);
    add_menu_item(menuEdit, wxString(wxT("Paste\tCtrl+V")), ID_Paste);
    add_menu_item(menuEdit, wxString(wxT("Delete\tDel")), ID_Delete);
    menuEdit->AppendSeparator();
    add_menu_item(menuEdit, wxString(wxT("Find...\tCtrl+F")), ID_Find);
    add_menu_item(menuEdit, wxString(wxT("Find Next\tF3")), ID_FindNext);
    add_menu_item(menuEdit, wxString(wxT("Find Previous\tShift+F3")),
                  ID_FindPrevious);
    add_menu_item(menuEdit, wxString(wxT("Replace...\tCtrl+H")), ID_Replace);
    add_menu_item(menuEdit, wxString(wxT("Go To...\tCtrl+G")), ID_GoTo);
    menuEdit->AppendSeparator();
    add_menu_item(menuEdit, wxString(wxT("Select All\tCtrl+A")), ID_SelectAll);
    add_menu_item(menuEdit, wxString(wxT("Time/Date\tF5")), ID_TimeDate);

    add_menu_item(menuFormat, wxString(wxT("Word Wrap")), ID_WordWrap);
    add_menu_item(menuFormat, wxString(wxT("Font...")), ID_Font);

    menuView->AppendSubMenu(menuZoom, wxString(wxT("Zoom")));
    add_menu_item(menuZoom, wxString(wxT("Zoom In\tCtrl++")), ID_ZoomIn);
    add_menu_item(menuZoom, wxString(wxT("Zoom Out\tCtrl+-")), ID_ZoomOut);
    add_menu_item(menuZoom, wxString(wxT("Restore Default Zoom\tCtrl+0")),
                  ID_RestoreDefaultZoom);
    add_menu_item(menuView, wxString(wxT("Status Bar")), ID_StatusBar);

    add_menu_item(menuHelp, wxString(wxT("View Help")), ID_ViewHelp);
    add_menu_item(menuHelp, wxString(wxT("Send Feedback")), ID_SendFeedback);
    menuHelp->AppendSeparator();
    add_menu_item(menuHelp, wxString(wxT("About Notepad")), ID_AboutNotepad);

    menuBar->Append(menuFile, wxT("File"));
    menuBar->Append(menuEdit, wxT("Edit"));
    menuBar->Append(menuFormat, wxT("Format"));
    menuBar->Append(menuView, wxT("View"));
    menuBar->Append(menuHelp, wxT("Help"));

    this->SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &Frame::New, this, ID_New);
    Bind(wxEVT_MENU, &Frame::NewWindow, this, ID_New_Window);
    Bind(wxEVT_MENU, &Frame::Open, this, ID_Open);
    Bind(wxEVT_MENU, &Frame::Save, this, ID_Save);
    Bind(wxEVT_MENU, &Frame::SaveAs, this, ID_Save_As);
    Bind(wxEVT_MENU, &Frame::Exit, this, ID_Exit);

    Bind(wxEVT_MENU, &Frame::Undo, this, ID_Undo);
    Bind(wxEVT_MENU, &Frame::Cut, this, ID_Cut);
    Bind(wxEVT_MENU, &Frame::Copy, this, ID_Copy);
    Bind(wxEVT_MENU, &Frame::Paste, this, ID_Paste);
    Bind(wxEVT_MENU, &Frame::Delete, this, ID_Delete);
    Bind(wxEVT_MENU, &Frame::Find, this, ID_Find);
    Bind(wxEVT_MENU, &Frame::FindNext, this, ID_FindNext);
    Bind(wxEVT_MENU, &Frame::FindPrevious, this, ID_FindPrevious);
    Bind(wxEVT_MENU, &Frame::Replace, this, ID_Replace);
    Bind(wxEVT_MENU, &Frame::GoTo, this, ID_GoTo);
    Bind(wxEVT_MENU, &Frame::SelectAll, this, ID_SelectAll);
    Bind(wxEVT_MENU, &Frame::TimeDate, this, ID_TimeDate);

    Bind(wxEVT_MENU, &Frame::WordWrap, this, ID_WordWrap);
    Bind(wxEVT_MENU, &Frame::Font, this, ID_Font);

    Bind(wxEVT_MENU, &Frame::ZoomIn, this, ID_ZoomIn);
    Bind(wxEVT_MENU, &Frame::ZoomOut, this, ID_ZoomOut);
    Bind(wxEVT_MENU, &Frame::RestoreDefaultZoom, this, ID_RestoreDefaultZoom);
    Bind(wxEVT_MENU, &Frame::StatusBar, this, ID_StatusBar);

    Bind(wxEVT_MENU, &Frame::ViewHelp, this, ID_ViewHelp);
    Bind(wxEVT_MENU, &Frame::SendFeedback, this, ID_SendFeedback);
    Bind(wxEVT_MENU, &Frame::AboutNotepad, this, ID_AboutNotepad);

    int widths[] = {-1, 100, 100, 100, 100};
    this->m_statusBar->SetFieldsCount(5, widths);

    this->RedrawStatusBar();

    wxConfig *config = new wxConfig("wxNotepad");

    bool wrap = config->ReadBool("linewrap", true);

    config->Write("linewrap", wrap);

    delete config;

    if (wrap) {
      if (this->m_textCtrl->GetWindowStyleFlag() & wxTE_DONTWRAP) {
        this->m_textCtrl->ToggleWindowStyle(wxTE_DONTWRAP);
      }
    } else {
      if (!(this->m_textCtrl->GetWindowStyleFlag() & wxTE_DONTWRAP)) {
        this->m_textCtrl->ToggleWindowStyle(wxTE_DONTWRAP);
      }
    }
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
        this->filename = dialog.GetPath();
        this->m_textCtrl->SetModified(false);
      }
    }
    this->UpdateTitle();

    return;
  }

  void Exit(wxCommandEvent &event) { this->Destroy(); }

  void Undo(wxCommandEvent &event) { this->m_textCtrl->Undo(); }

  void Cut(wxCommandEvent &event) { this->m_textCtrl->Cut(); }

  void Copy(wxCommandEvent &event) { this->m_textCtrl->Copy(); }

  void Paste(wxCommandEvent &event) { this->m_textCtrl->Paste(); }

  void Delete(wxCommandEvent &event) {
    long from;
    long to;
    this->m_textCtrl->GetSelection(&from, &to);
    this->m_textCtrl->Remove(from, to);
  }

  void Find(wxCommandEvent &event) {
    new FindStrWindow(this, this->m_textCtrl);
  }

  void FindNext(wxCommandEvent &event) {}

  void FindPrevious(wxCommandEvent &event) {}

  void Replace(wxCommandEvent &event) {}

  void GoTo(wxCommandEvent &event) { new GoToWindow(this, this->m_textCtrl); }

  void SelectAll(wxCommandEvent &event) {
    this->m_textCtrl->SetSelection(0, -1);
  }

  void TimeDate(wxCommandEvent &event) {
    wxString str = "";
    wxDateTime dt = wxDateTime::Now();

    // Hour
    if (dt.GetHour() > 12) {
      str += std::to_string(dt.GetHour() - 12);
    } else {
      str += std::to_string(dt.GetHour());
    }
    str += ":";

    // Minute
    for (int i = 0; i < 2 - std::to_string(dt.GetMinute()).length(); i++) {
      str += "0";
    }
    str += std::to_string(dt.GetMinute());

    // AM/PM
    if (dt.GetHour() > 12) {
      str += " PM ";
    } else {
      str += " AM ";
    }

    str += std::to_string(dt.GetMonth() + 1);
    str += "/";
    str += std::to_string(dt.GetDay());
    str += "/";
    str += std::to_string(dt.GetYear());
    this->m_textCtrl->WriteText(str);
  }

  void WordWrap(wxCommandEvent &event) {

    wxConfig *config = new wxConfig("wxNotepad");

    bool wrap = config->ReadBool("linewrap", true);

    wrap = !wrap;

    config->Write("linewrap", wrap);

    delete config;

    if (wrap) {
      if (this->m_textCtrl->GetWindowStyleFlag() & wxTE_DONTWRAP) {
        this->m_textCtrl->ToggleWindowStyle(wxTE_DONTWRAP);
      }
    } else {
      if (!(this->m_textCtrl->GetWindowStyleFlag() & wxTE_DONTWRAP)) {
        this->m_textCtrl->ToggleWindowStyle(wxTE_DONTWRAP);
      }
    }
  }

  void Font(wxCommandEvent &event) {}

  void ZoomIn(wxCommandEvent &event) {
    this->zoomLevel += 10;
    if (this->zoomLevel > 500) {
      this->zoomLevel = 500;
    }

    this->UpdateFontSize();
  }

  void ZoomOut(wxCommandEvent &event) {
    this->zoomLevel -= 10;
    if (this->zoomLevel < 10) {
      this->zoomLevel = 10;
    }

    this->UpdateFontSize();
  }

  void RestoreDefaultZoom(wxCommandEvent &event) {
    this->zoomLevel = 100;

    this->UpdateFontSize();
  }

  void StatusBar(wxCommandEvent &event) {
    bool shown = this->m_statusBar->IsShown();
    this->m_statusBar->Show(!shown);
  }

  void ViewHelp(wxCommandEvent &event) {
    wxMimeTypesManager manager;
    wxFileType *filetype = manager.GetFileTypeFromExtension("html");
    wxString command = filetype->GetOpenCommand(
        "https://github.com/samchristywork/wx-notepad/");
    wxExecute(command);
  }

  void SendFeedback(wxCommandEvent &event) {
    wxMimeTypesManager manager;
    wxFileType *filetype = manager.GetFileTypeFromExtension("html");
    wxString command = filetype->GetOpenCommand(
        "https://github.com/samchristywork/wx-notepad/issues/");
    wxExecute(command);
  }

  void AboutNotepad(wxCommandEvent &event) {}

  void UpdateFontSize() {
    wxFont font = this->m_textCtrl->GetFont();
    font.SetPointSize(12 * this->zoomLevel / 100);
    this->m_textCtrl->SetFont(font);
  }

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
    str += std::to_string(y);
    str += ", Col ";
    str += std::to_string(x);

    this->m_statusBar->SetStatusText(str, 1);

    this->m_statusBar->SetStatusText(std::to_string(this->zoomLevel) + "%", 2);

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
    Frame *f = new Frame(NULL);
    f->LoadFile(wxApp::argv[i]);
  }

  return true;
}

wxIMPLEMENT_APP(App);
