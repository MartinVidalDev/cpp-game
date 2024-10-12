#ifndef __APPWINDOW_H__
#define __APPWINDOW_H__

#include <Window.h>

class AppWindow : public Window
{
	AppWindow();
	~AppWindow();

	//Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDelete() override;
};

#endif