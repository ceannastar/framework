//
//	File: input.h
//
//
// 	Author: Alexandr Sotnikov
//	Date: 20 September 2022
//

#include "input_common.h"
#include <iostream>

bool Framework::deviceinput_c::__initialize_input_devices(HINSTANCE hInstance)
{
	IDirectInput8* directinput = nullptr;
	IDirectInputDevice8* diKeyboard = nullptr;
	
	HRESULT result = DirectInput8Create(hInstance, 0x0800, IID_IDirectInput8, (void**)&directinput, nullptr);
	
	if(result != DI_OK)
	{
		switch(result)
		{
			case DIERR_OLDDIRECTINPUTVERSION: {std::cout << "DirectInput reports: Old version of drivers." << std::endl; break;}
			case DIERR_INVALIDPARAM: {std::cout << "DirectInput reports: Invalid parameters." << std::endl; break;}
			case DIERR_OUTOFMEMORY: {std::cout << "DirectInput reports: out of memory." << std::endl;break;}
			case DIERR_BETADIRECTINPUTVERSION: {std::cout << "DirectInput reports: Beta version of library." << std::endl;break;}

		}
	}
	
	//directinput->CreateDevice(GUID_SysKeyboard,&diKeyboard, nullptr);
	
	
	return true;
}