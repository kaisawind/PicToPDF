#ifndef __BMP_H__
#define __BMP_H__
#include "Picture.h"


#define BMPTYPE				(0x424D)
#define BMP_HEADER_SIZE		(14)
#define BMP_DOUBLE_COLOR	(0x01)
#define BMP_16_COLOR		(0x04)
#define BMP_256_COLOR		(0x08)
#define BMP_HIGH_COLOR		(0x16)
#define BMP_TRUE_COLOR		(0x24)

//BMP文件头（14字节）
struct BITMAPFILEHEADER
{
    UINT16 bfType;		//位图文件的类型，必须为BM(1-2字节）
    UINT32 bfSize;		//位图文件的大小，以字节为单位（3-6字节，低位在前）
    UINT16 bfReserved1;	//位图文件保留字，必须为0(7-8字节）
    UINT16 bfReserved2;	//位图文件保留字，必须为0(9-10字节）
    UINT32 bfOffBits;	//位图数据的起始位置，以相对于位图（11-14字节，低位在前）
    					//文件头的偏移量表示，以字节为单位
};

//位图信息头（40字节）
struct BITMAPINFOHEADER
{
	UINT32 biSize;			//本结构所占用字节数（15-18字节）
	UINT32 biWidth;			//位图的宽度，以像素为单位（19-22字节）
	UINT32 biHeight;		//位图的高度，以像素为单位（23-26字节）
	UINT16 biPlanes;		//目标设备的级别，必须为1(27-28字节）
	UINT16 biBitCount;		//每个像素所需的位数，必须是1（双色），（29-30字节）
							//4(16色），8(256色）16(高彩色)或24（真彩色）之一
	UINT32 biCompression;	//位图压缩类型，必须是0（不压缩），（31-34字节）
							//1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一
	UINT32 biSizeImage;		//位图的大小(其中包含了为了补齐行数是4的倍数而添加的空字节)，以字节为单位（35-38字节）
	UINT32 biXPelsPerMeter;	//位图水平分辨率，每米像素数（39-42字节）
	UINT32 biYPelsPerMeter;	//位图垂直分辨率，每米像素数（43-46字节)
	UINT32 biClrUsed;		//位图实际使用的颜色表中的颜色数（47-50字节）
	UINT32 biClrImportant;	//位图显示过程中重要的颜色数（51-54字节）
};

struct RGBQUAD
{
	UINT8 rgbBlue;			//蓝色的亮度（值范围为0-255)
	UINT8 rgbGreen;			//绿色的亮度（值范围为0-255)
	UINT8 rgbRed;			//红色的亮度（值范围为0-255)
	UINT8 rgbReserved;		//保留，必须为0
};

struct RGB
{
	UINT8 b;
	UINT8 g;
	UINT8 r;
};

class Bmp : public Picture
{
public:
	Bmp();
	~Bmp();
	Bmp(string image);
	void procPicture();
	int getBmpSize();
	bool getIsBmp();

private:
	void readHeader();
	void readInfo();
	void readRGBQuad();
	void readPicData();

private:
	bool m_isbmpfile;
	int m_bmpsize;
	int m_width;
	int m_height;
	int m_infosize;
	UINT8 m_bitCount;
	int m_offBits;
};

#endif //__BMP_H__