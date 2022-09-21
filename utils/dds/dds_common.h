//
//	File: dds_common.h
//
//
// 	Author: Alexandr Sotnikov
//	Date: 19 September 2022
//

namespace ceanns__dds
{
	
	#define DDSM 0x20534444
	#define DDPF_ALPHAPIXELS 0x1
	#define DDPF_ALPHA 0x2
	#define DDPF_FOURCC 0x4
	#define DDPF_RGB 0x40
	#define DDPF_YUV 0x200
	#define DDPF_LUMINANCE 0x20000


	
	class DDS_c
	{
		private:
			typedef struct {
				unsigned int size;
				unsigned int flags;
				unsigned int fourCC;
				unsigned int rgbbitcount;
				unsigned int rbitmask;
				unsigned int gbitmask;
				unsigned int bbitmask;
				unsigned int abitmask;
			} dds_pixformat;
		
			typedef struct {
				unsigned int size;
				unsigned int flags;
				unsigned int height;
				unsigned int width;
				unsigned int pitch_or_linear_size;
				unsigned int depth;
				unsigned int mmcount;
				unsigned int reserved[11];
				dds_pixformat d_pixformat;
				unsigned int caps[4];
				unsigned int reserved2;
			} dds_head;
			
		private:
		
			bool __read_r8g8b8(int miplevels);
			
		public:
			bool __load_dds(const char* fname, unsigned char* data, int width, int height);
	};
}