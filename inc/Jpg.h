#ifndef __JPG_H__
#define __JPG_H__
#include "Picture.h"

#define SEGMENT_IDENTIFICATION (0xFF)

enum TagCode
{
	SOI    = 0xD8,     // 文件头 
	EOI    = 0xD9,     // 文 件尾  
	SOF0   = 0xC0,     // 帧开始（标准 JPEG） 
	SOF1   = 0xC1,     // 同上  
	DHT    = 0xC4,     // 定 义 Huffman 表（霍夫曼表） 
	SOS    = 0xDA,     // 扫描行开始 
	DQT    = 0xDB,     // 定义量化表  
	DRI    = 0xDD,     // 定 义重新开始间隔  
	APP0   = 0xE0,     // 定义交换格式和图像识别信息 
	COM    = 0xFE      // 注释 
};

class Jpg : public Picture
{
public:
	Jpg();
	Jpg(string image);
	~Jpg();
	void procPicture();

private:

private:

};

#endif //__JPG_H__