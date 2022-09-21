
#include "dds_common.h"

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>

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
			PAINTSTRUCT ps;
			HDC hDC = BeginPaint(_handle_window, &ps);
			
			int width = 50, height = 50;
			unsigned char* bits = new unsigned char[3*width*height];
			ceanns__dds::DDS_c* dds = new ceanns__dds::DDS_c;
	
			dds->__load_dds("image_bgr.dds", bits, width, height);
			
			std::cout << bits[155] << std::endl;
			
			    BITMAPINFO* ptr = new BITMAPINFO;
				ptr->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
				ptr->bmiHeader.biWidth = width;
				ptr->bmiHeader.biHeight = height;
				ptr->bmiHeader.biPlanes = 1;
				ptr->bmiHeader.biBitCount = 24;
				ptr->bmiHeader.biCompression = BI_RGB;
			
			StretchDIBits(hDC, 0,0, width, height, 0, 0, width,height, bits, ptr, DIB_PAL_COLORS, MERGECOPY);
			
			EndPaint(_handle_window, &ps);
			
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