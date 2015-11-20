#ifndef TutorialApp_h__
#define TutorialApp_h__

#include "stdwx.h"

#include "MainFrame.h"


class MainApp : public wxApp
{
public:
	// override base class virtuals
	// ----------------------------
	virtual bool OnInit();
};


#endif // TutorialApp_h__