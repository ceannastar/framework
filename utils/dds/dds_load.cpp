//
//	File: dds_load.cpp
//
//
// 	Author: Alexandr Sotnikov
//	Date: 20 September 2022
//

#include "dds_common.h"

#include <iostream>
#include <fstream>

bool ceanns__dds::DDS_c::__load_dds(const char* fname, unsigned char* data, int width, int height)
{
	
	std::ifstream file(fname, std::ios::in | std::ios::binary);
	
	if(file.is_open())
	{
		unsigned int magic = 0;
		
		file.read((char*)&magic, 4);
		
		if(magic == DDSM)
		{
			dds_head d_head;
			
			file.read((char*)&d_head.size, sizeof d_head.size);
			if(d_head.size!=124)
			{
				std::cout << "Wrong DDS data" << std::endl;
				file.close();
				return false;
			}
			file.read((char*)&d_head.flags, sizeof d_head.flags);
			file.read((char*)&d_head.height, sizeof d_head.height);
			file.read((char*)&d_head.width, sizeof d_head.width);
			file.read((char*)&d_head.pitch_or_linear_size, sizeof d_head.pitch_or_linear_size);
			file.read((char*)&d_head.depth, sizeof d_head.depth);
			file.read((char*)&d_head.mmcount, sizeof d_head.mmcount);	
			for(int i = 0; i < 11; i++)			
				file.read((char*)&d_head.reserved[i], sizeof d_head.reserved[i]);
			{
				file.read((char*)&d_head.d_pixformat.size, sizeof d_head.d_pixformat.size);	
				if(d_head.d_pixformat.size!=32)
				{
					std::cout << "Wrong DDS data" << std::endl;
					file.close();
					return false;
				}
				file.read((char*)&d_head.d_pixformat.flags, sizeof d_head.d_pixformat.flags);	
				file.read((char*)&d_head.d_pixformat.fourCC, sizeof d_head.d_pixformat.fourCC);
				file.read((char*)&d_head.d_pixformat.rgbbitcount, sizeof d_head.d_pixformat.rgbbitcount);
				file.read((char*)&d_head.d_pixformat.rbitmask, sizeof d_head.d_pixformat.rbitmask);
				file.read((char*)&d_head.d_pixformat.gbitmask, sizeof d_head.d_pixformat.gbitmask);
				file.read((char*)&d_head.d_pixformat.bbitmask, sizeof d_head.d_pixformat.bbitmask);
				file.read((char*)&d_head.d_pixformat.abitmask, sizeof d_head.d_pixformat.abitmask);
			}
			for(int i = 0; i < 4; i++)			
				file.read((char*)&d_head.caps[i], sizeof d_head.caps[i]);
			file.read((char*)&d_head.reserved2, sizeof d_head.reserved2);

			width = d_head.width;
			height = d_head.height;
			
			int bitcount = 3;
			
			data = new unsigned char[bitcount*width*height];

			{
				//for(int i = 0; i < 1; i++)
				{
					for(int j = 0; j < 3*133*100; j += 3)
					{
						data[j] = 50;
						data[j+1] = 51;
						data[j+2] = 50;
					}
				}
			}				
			
		}
		else
		{
			std::cout << "Wrong format data" << std::endl;
			return false;
		}
	}
	else
	{

		std::cout << "Could not open the file" << std::endl;
	}
	
	file.close();
	
	return true;
}