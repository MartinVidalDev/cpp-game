#pragma once
#include <Windows.h>

class Window
{
public:
	Window();

	// Initialize the Window
	bool init();
	bool broadcast();

	// Release the Window
	bool release();
	bool isRun();

	//EVENTS
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();

	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};
