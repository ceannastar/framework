//
//	File: input_common.h
//
//
// 	Author: Alexandr Sotnikov
//	Date: 20 September 2022
//

#include <dinput.h>

namespace Framework
{
	class deviceinput_c
	{
		private:
			
			
		public:
			bool __initialize_input_devices(HINSTANCE hInstance);
	};
}