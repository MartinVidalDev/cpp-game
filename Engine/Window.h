#ifndef __WINDOW_H__
#define __WINDOW_H__
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
	virtual void onCreate()=0;
	virtual void onUpdate()=0;
	virtual void onDestroy();

	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};

#endif