#include "AppWindow.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
}

void AppWindow::onUpdate()
{
}

void AppWindow::onDelete()
{
	Window::onDestroy();
}
