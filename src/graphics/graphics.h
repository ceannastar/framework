//
//	File: graphics.h
//
//
// 	Author: Alexandr Sotnikov
//	Date: 20 September 2022
//

#include <d3d9.h>

namespace Framework
{			

	typedef struct
	{
		int width; int height;
		bool fullscreen = false;
		bool vsync = false;
	} *graphics_param;
		
	class graphics_c
	{
		
		private:
			bool __initialize_directx9_device(HWND hWnd);
		
		public:
			bool __initialize(HWND hWnd);
			void __renderframe();
			void __releaseCOM();
	};
}