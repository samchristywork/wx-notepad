///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/radiobox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxStatusBar* m_statusBar;
		wxTextCtrl* m_textCtrl;

		// Virtual event handlers, override them in your derived class
		virtual void KeyDownCallback( wxKeyEvent& event ) { event.Skip(); }
		virtual void KeyUpCallback( wxKeyEvent& event ) { event.Skip(); }
		virtual void PaintCallback( wxPaintEvent& event ) { event.Skip(); }
		virtual void TextCallback( wxCommandEvent& event ) { event.Skip(); }
		virtual void UpdateUICallback( wxUpdateUIEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class GoToFrame
///////////////////////////////////////////////////////////////////////////////
class GoToFrame : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrl2;
		wxPanel* m_panel1;
		wxButton* m_button1;
		wxButton* m_button2;

	public:

		GoToFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Go To Line"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~GoToFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame3
///////////////////////////////////////////////////////////////////////////////
class MyFrame3 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl3;
		wxStaticText* m_staticText3;
		wxPanel* m_panel2;
		wxRadioBox* m_radioBox1;
		wxButton* m_button6;
		wxButton* m_button7;

	public:

		MyFrame3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Find"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame3();

};

