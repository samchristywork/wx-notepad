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

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Line number:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALL, 5 );

	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer2->Add( m_textCtrl2, 0, wxALL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer3->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );

	m_button1 = new wxButton( this, wxID_ANY, wxT("Go To"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button2, 0, wxALL, 5 );


	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_textCtrl2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GoToFrame::GoToLineEnterCallback ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GoToFrame::GoToClickCallback ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GoToFrame::GoToCancelCallback ), NULL, this );
}

GoToFrame::~GoToFrame()
{
	// Disconnect Events
	m_textCtrl2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GoToFrame::GoToLineEnterCallback ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GoToFrame::GoToClickCallback ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GoToFrame::GoToCancelCallback ), NULL, this );

}

FindFrame::FindFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Find what"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer8->Add( m_staticText2, 0, wxALL, 5 );

	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_textCtrl3, 0, wxALL, 5 );


	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );


	bSizer5->Add( bSizer7, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer9->Add( m_staticText3, 0, wxALL, 5 );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer9->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );

	wxString m_radioBox1Choices[] = { wxT("Up"), wxT("Down") };
	int m_radioBox1NChoices = sizeof( m_radioBox1Choices ) / sizeof( wxString );
	m_radioBox1 = new wxRadioBox( this, wxID_ANY, wxT("Direction"), wxDefaultPosition, wxDefaultSize, m_radioBox1NChoices, m_radioBox1Choices, 1, wxRA_SPECIFY_ROWS );
	m_radioBox1->SetSelection( 0 );
	bSizer9->Add( m_radioBox1, 0, wxALL, 5 );


	bSizer5->Add( bSizer9, 1, wxEXPAND, 5 );


	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Find Next"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button6, 0, wxALL, 5 );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button7, 0, wxALL, 5 );


	bSizer4->Add( bSizer6, 0, 0, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_textCtrl3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FindFrame::FindEnterCallback ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindFrame::FindNextClickCallback ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindFrame::CancelClickCallback ), NULL, this );
}

FindFrame::~FindFrame()
{
	// Disconnect Events
	m_textCtrl3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FindFrame::FindEnterCallback ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindFrame::FindNextClickCallback ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindFrame::CancelClickCallback ), NULL, this );

}
