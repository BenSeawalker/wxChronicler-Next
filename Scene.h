#ifndef Scene_h__
#define Scene_h__

#include "stdwx.h"
#include "wx/notebook.h"

class Scene : public wxPanel
{
public:
	Scene(wxWindow * _parent, wxWindowID _id = wxID_ANY, const wxString & _title = "" );
	~Scene();

// Members
private:
	wxString m_title;

	wxPanel * m_panel;
	wxNotebook * m_scenes;
	wxWindow * m_view;

};

#endif // Scene_h__
