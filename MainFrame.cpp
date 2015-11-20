#include "stdwx.h"

#include "MainFrame.h"

// IDs for the controls and the menu commands
enum
{
	WND_Paint = 100,

	MNU_Quit = wxID_EXIT,
	MNU_About = wxID_ABOUT,
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_MENU(MNU_Quit, MainFrame::OnQuit)
	EVT_MENU(MNU_About, MainFrame::OnAbout)
wxEND_EVENT_TABLE();




MainFrame::MainFrame(const wxString & _title, const wxPoint & _pos, const wxSize & _size)
	: wxFrame(nullptr, wxID_ANY, _title, _pos, _size)
{
	// set the frame icon
	SetIcon(wxICON(sample));
	MenuBar();
	Panel();
}


void MainFrame::MenuBar()
{
#if wxUSE_MENUS
	// create a menu bar
	wxMenu *fileMenu = new wxMenu;

	// the "About" item should be in the help menu
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(MNU_About, "&About\tF1", "Show about dialog");

	fileMenu->Append(MNU_Quit, "E&xit\tAlt-X", "Quit this program");

	// now append the freshly created menu to the menu bar...
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);
#endif // wxUSE_MENUS

//#if wxUSE_STATUSBAR
//	// create a status bar just for fun (by default with 1 pane only)
//	CreateStatusBar(2);
//	SetStatusText("Welcome to wxWidgets!");
//#endif // wxUSE_STATUSBAR
}

void MainFrame::Panel()
{
	//m_paintWindow = new wxWindow(this, WND_Paint);
	//m_paintWindow->Connect(WND_Paint, wxID_ANY, wxEVT_PAINT, (wxObjectEventFunction)&MainFrame::OnPaint, nullptr, this);
	//m_paintWindow->Connect(WND_Paint, wxID_ANY, wxEVT_MOTION, (wxObjectEventFunction)&MainFrame::OnMotion, nullptr, this);

	// Initialization
	m_panel = new wxPanel(this);
	//m_scene = new Scene(m_panel, wxID_ANY, "startup");
	wxNotebook * scenes = new wxNotebook(m_panel, wxID_ANY);
	m_sideBar = new wxPanel(m_panel, wxID_ANY, wxDefaultPosition, wxSize(200,400), wxBORDER_STATIC);

	// Local
	// Sizer
	wxBoxSizer * hrzSizer = new wxBoxSizer(wxHORIZONTAL);
	//wxBoxSizer * vrtSizer = new wxBoxSizer(wxVERTICAL);

	// Items
	//wxButton * temp = new wxButton(this, wxID_ANY, "temp");
	//wxNotebook * scenes = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(0,100));

	wxNotebookPage * page = new wxNotebookPage(scenes, wxID_ANY);
	//page->SetLabel("startup");

	scenes->AddPage(page, "startup", true);
	
	//vrtSizer->Add(scenes, 0, wxGROW | wxALL, 1);
	//vrtSizer->Add(m_scene, 1, wxGROW | wxALL, 1);

	hrzSizer->Add(scenes, 1, wxGROW | wxALL, 5);
	hrzSizer->Add(m_sideBar, 0, wxGROW | wxALL | wxSTRETCH_NOT, 5);

	m_panel->SetAutoLayout(true);
	m_panel->SetSizer(hrzSizer);
}



void MainFrame::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	// true is to force the frame to close
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent & WXUNUSED(event))
{
	wxMessageBox(wxString::Format
		(
			"Welcome to %s!\n"
			"\n"
			"This is the minimal wxWidgets sample\n"
			"running under %s.",
			wxVERSION_STRING,
			wxGetOsDescription()
			),
		"About wxWidgets minimal sample",
		wxOK | wxICON_INFORMATION,
		this);
}

//void MainFrame::OnPaint(wxPaintEvent & WXUNUSED(event))
//{
//	wxPaintDC dc(m_paintWindow);
//
//	wxBitmap bmp = wxBITMAP(Weasel);
//	bmp.SetMask(new wxMask(bmp, wxColor(0, 0, 0)));
//
//	dc.DrawBitmap(bmp, 10, 20, true);
//
//	//dc.DrawText("Painting...", 10, 20);
//}
//
//
//void MainFrame::OnMotion(wxMouseEvent & event)
//{
//	wxClientDC dest(m_paintWindow);
//
//	if (event.LeftIsDown())
//	{
//		dest.SetPen(*wxWHITE_PEN);
//		dest.SetBrush(*wxWHITE_BRUSH);
//		dest.DrawCircle(event.GetPosition(), 10);
//	}
//	else if (event.RightIsDown())
//	{
//		dest.SetPen(*wxRED_PEN);
//		dest.SetBrush(*wxRED_BRUSH);
//		dest.DrawCircle(event.GetPosition(), 10);
//	}
//}