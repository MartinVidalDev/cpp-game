#include "Window.h"

Window* window = nullptr;

Window :: Window()
{

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        // Event fired when the window will be created
        window->onCreate();
        break;
    }
    case WM_DESTROY:
    {
        // Event dired when the windiw will be destroyed
        window->onDestroy();
        ::PostQuitMessage(0);
        break;
    }

    default:
        return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }
}

bool Window :: init()
{
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL; // Specify number of additional bytes for WNDCLASSEX structure
    wc.cbSize = sizeof(WNDCLASSEX); // Specifies the size of the WNDCLASSEX structure in bytes
    wc.cbWndExtra = NULL; // Specifies the number of additional bytes to be allocated after the window structure
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW; // Specifies the brush used to draw the window background with its color
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Sets the default cursor used for the window
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Sets the default icon used for the window
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION); // Specifies the small icon used in the taskbar or when the window is minimized
    wc.hInstance = NULL; // Keeps a reference to the application instance
    wc.lpszClassName = "MyWindowClass"; // This is the name of the window class
    wc.lpszMenuName = ""; // The name of the default menu associated with the window
    wc.style = NULL; // Specify window style
    wc.lpfnWndProc = &WndProc ;

    // If the registration of class will fail, the function will return false
    if (!::RegisterClassEx(&wc))
        return false;

    if (!window)
        window = this;

    // Creation of the window
    m_hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "DirectX application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

    // If the creation fail, return false
    if (!m_hwnd)
        return false;

    // Show up the window
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);

    // Set this flag to true to indicate that the window is initialized and running
    m_is_run = true;

    return true;
}

bool Window::broadcast()
{
    MSG msg;

    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    window->onUpdate();

    Sleep(0);

    return true;
}

bool Window :: release()
{
    // Destroy the window
    if (!::DestroyWindow(m_hwnd))
        return false;

    return true;
}

bool Window::isRun()
{
    return m_is_run;
}

void Window::onDestroy()
{
    m_is_run = false;
}

Window :: ~Window()
{

}