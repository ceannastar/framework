#include <Windows.h>
#include <iostream>
#include <fstream>

#include "src/graphics/graphics.h"

LRESULT CALLBACK WndProc(HWND _handle_window, UINT _message, WPARAM wparam, LPARAM lparam)
{
	switch (_message)
	{
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		case WM_PAINT:
		{
			break;
		}
	}

	return DefWindowProc(_handle_window, _message, wparam, lparam);
}

int main()
{
	HINSTANCE hInst;
	WNDCLASS wnd = { };

	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInst;
	wnd.lpszClassName = "p";

	RegisterClass(&wnd);

	HWND hWnd = CreateWindow("p", "Simple Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInst, nullptr);

	ShowWindow(hWnd, true);
	
	Framework::graphics_c* graphics = new Framework::graphics_c;
	
	if(!graphics->__initialize(hWnd))
		return 1;
	
	MSG msg = { };
	
	while(GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	graphics->__releaseCOM();

	return 0;
}