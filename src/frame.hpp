#ifndef FRAME_H
#define FRAME_H

#include <wx/textfile.h>

#include "../codegen/noname.h"

class Frame : public MainFrame {
public:
  wxString filename = "";
  wxTextFileType fileType;
  int zoomLevel = 100;
  wxString textEncoding = "UTF-8";

  Frame(wxWindow *parent);
  void UpdateTitle();
  void New(wxCommandEvent &event);
  void NewWindow(wxCommandEvent &event);
  void Open(wxCommandEvent &event);
  void Save(wxCommandEvent &event);
  void SaveAs(wxCommandEvent &event);
  void Exit(wxCommandEvent &event);
  void Undo(wxCommandEvent &event);
  void Cut(wxCommandEvent &event);
  void Copy(wxCommandEvent &event);
  void Paste(wxCommandEvent &event);
  void Delete(wxCommandEvent &event);
  void Find(wxCommandEvent &event);
  void FindNext(wxCommandEvent &event);
  void FindPrevious(wxCommandEvent &event);
  void Replace(wxCommandEvent &event);
  void GoTo(wxCommandEvent &event);
  void SelectAll(wxCommandEvent &event);
  void TimeDate(wxCommandEvent &event);
  void WordWrap(wxCommandEvent &event);
  void Font(wxCommandEvent &event);
  void ZoomIn(wxCommandEvent &event);
  void ZoomOut(wxCommandEvent &event);
  void RestoreDefaultZoom(wxCommandEvent &event);
  void StatusBar(wxCommandEvent &event);
  void ViewHelp(wxCommandEvent &event);
  void SendFeedback(wxCommandEvent &event);
  void AboutNotepad(wxCommandEvent &event);
  void UpdateFontSize();
  void ManualLoadFile(wxString filename);
  void LoadFileWithLineEndings(wxString filename);
  void LoadFile(wxString filename);
  void UpdateUICallback(wxUpdateUIEvent &event);
  void RedrawStatusBar();
};

#endif
