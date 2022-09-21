//
//	File: graphics.cpp
//
//
// 	Author: Alexandr Sotnikov
//	Date: 20 September 2022
//

#include "graphics.h"

bool Framework::graphics_c::__initialize(HWND hWnd)
{
	
	__initialize_directx9_device(hWnd);
	
	return true;
}

