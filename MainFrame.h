#ifndef MainFrame_h__
#define MainFrame_h__

#include "stdwx.h"
#include "Scene.h"
#include "wx/notebook.h"

class MainFrame : public wxFrame
{
// ctor(s)
public:
	MainFrame(const wxString & _title, const wxPoint & _pos = wxDefaultPosition, const wxSize & _size = wxDefaultSize);

// Setter/Getter(s)
public:
	void SetScene(Scene * _scene) { m_scene = _scene; };
	Scene * const GetScene() { return m_scene; };


// Members
private: 
	//wxWindow * m_paintWindow;
	wxPanel * m_panel;
	Scene * m_scene;
	wxPanel * m_sideBar;

// Methods
private: 
	void MenuBar();
	void Panel();

// Events
private: 
	// any class wishing to process wxWidgets events must use this macro
	wxDECLARE_EVENT_TABLE();

	// event handlers (these functions should _not_ be virtual)
	void OnQuit(wxCommandEvent & event);
	void OnAbout(wxCommandEvent & event);

	void OnPaint(wxPaintEvent & event);
	void OnMotion(wxMouseEvent & event);
};

#endif // MainFrame_h__