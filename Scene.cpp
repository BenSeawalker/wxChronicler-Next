#include "stdwx.h"
#include "Scene.h"

Scene::Scene(wxWindow * _parent, wxWindowID _id, const wxString & _title)
	: wxPanel(_parent, _id, wxDefaultPosition, wxDefaultSize, wxBORDER_STATIC), m_title(_title)
{

	m_panel = new wxPanel(this);
	m_scenes = new wxNotebook(m_panel, wxID_ANY, wxDefaultPosition, wxSize(0,100));
	m_view = new wxWindow(m_panel, wxID_ANY);

	wxBoxSizer * vrtSizer = new wxBoxSizer(wxVERTICAL);


	m_panel->SetAutoLayout(true);
	m_panel->SetSizer(vrtSizer);
}

Scene::~Scene()
{}
