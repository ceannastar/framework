//
//	File: dx9.cpp
//
//
// 	Author: Alexandr Sotnikov
//	Date: 20 September 2022
//

#include "graphics.h"

#include <iostream>

IDirect3D9* g_d3d9 = nullptr;
IDirect3DDevice9* g_d3dd9 = nullptr;

bool Framework::graphics_c::__initialize_directx9_device(HWND hWnd)
{
	
	
	if(nullptr == (g_d3d9 = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		std::cout << "DirectX9 report: could not create DirectX object" << std::endl;
		return false;
	}
	
	D3DPRESENT_PARAMETERS d3dparams;
	memset(&d3dparams, 0, sizeof d3dparams);
	d3dparams.Windowed = TRUE;
	d3dparams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dparams.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dparams.hDeviceWindow = hWnd;
	d3dparams.BackBufferWidth = 1920;
	d3dparams.BackBufferHeight = 1080;
	
	HRESULT result = g_d3d9->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dparams, &g_d3dd9);
	if(result != D3D_OK)
	{
		switch(result)
		{
			case D3DERR_DEVICELOST: { std::cout << "DirectX9 report: device lost." << std::endl; break;}
			case D3DERR_INVALIDCALL: { std::cout << "DirectX9 report: invalid call." << std::endl; break;}
			case D3DERR_NOTAVAILABLE: { std::cout << "DirectX9 report: not available." << std::endl; break;}
			case D3DERR_OUTOFVIDEOMEMORY: { std::cout << "DirectX9 report: out of video memory." << std::endl; break;}
		}
	}
	
	return true;
}



void Framework::graphics_c::__releaseCOM()
{
	if(g_d3d9!=nullptr)
		g_d3d9->Release();
}