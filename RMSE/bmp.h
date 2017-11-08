#ifndef _BMP_H
#define _BMP_H
#include <iostream>
#include <assert.h>
using namespace std;

class _BMP 
{
public:
	_BMP();
	//~_BMP();
	inline int getWidth() { return width; }
	inline int getHeight() { return height; }
	void Load(const char*);
	void Save(const char*);
	void Conv2Gray();
	void DownSample(int);
	double RMSE(_BMP &);
	//void Rotate(double);

	unsigned char *ImgValue_s;          //Img RGB Info recently
	unsigned char *ImgValue_t;          //Img RGB Info changed

private:
	int width, height;        // image width, image height
	char factor;             // factor of downsample
	int  width_d, height_d;  // downsample_image width, height
	int rgb_raw_data_offset; // RGB raw data offset
	int file_size;           //file_size = width_d * height_d * 3  + rgb_raw_data_offset;
	int biSizeImage;
};

#endif