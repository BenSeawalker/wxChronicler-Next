#include "stdwx.h"

#include "MainApp.h"

bool MainApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	// create the main application window
	MainFrame *frame = new MainFrame("Chronicler-Next", wxDefaultPosition, wxSize(1280,720));

	frame->Show(true);

	return true;
}
