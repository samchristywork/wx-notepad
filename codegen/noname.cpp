///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_statusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer;
	bSizer = new wxBoxSizer( wxVERTICAL );

	m_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer->Add( m_textCtrl, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_textCtrl->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrame::KeyDownCallback ), NULL, this );
	m_textCtrl->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::KeyUpCallback ), NULL, this );
	m_textCtrl->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::PaintCallback ), NULL, this );
	m_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::TextCallback ), NULL, this );
	m_textCtrl->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::UpdateUICallback ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_textCtrl->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrame::KeyDownCallback ), NULL, this );
	m_textCtrl->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrame::KeyUpCallback ), NULL, this );
	m_textCtrl->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::PaintCallback ), NULL, this );
	m_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::TextCallback ), NULL, this );
	m_textCtrl->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::UpdateUICallback ), NULL, this );

}

GoToFrame::GoToFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );


	this->Centre( wxBOTH );
}

GoToFrame::~GoToFrame()
{
}
