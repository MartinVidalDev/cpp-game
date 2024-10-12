#ifndef __WINDOW_H__
#define __WINDOW_H__

class Window 
{
public:
	Window();

	// Initialize the Window
	bool init();

	// Release the Window
	bool release();

	~Window();
};

#endif