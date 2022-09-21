//
//	File: win32.c
//	Description: Uses as template
//
// 	Author: Alexandr Sotnikov
//	Date: 19 September 2022
//

#include <Windows.h>
#include <iostream>
#include <fstream>

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

	WNDCLASS wnd = { };

	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = GetModuleHandleA(nullptr);
	wnd.lpszClassName = "p";

	RegisterClass(&wnd);

	HWND hWnd = CreateWindow("p", "Simple Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, GetModuleHandleA(nullptr), nullptr);

	ShowWindow(hWnd, true);
	
	
	
	MSG msg = { };
	
	while(GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}