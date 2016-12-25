#include "Bmp.h"
#include <string.h>

Bmp::Bmp(string image) : Picture(image)
{
	m_isbmpfile =  false;
	m_bmpsize = 0;
	m_infosize = 0;
	m_width = 0;
	m_height = 0;
	m_bitCount = 0;
	m_offBits = 0;
}

Bmp::Bmp() : Picture()
{
	m_isbmpfile =  false;
	m_bmpsize = 0;
	m_infosize = 0;
	m_width = 0;
	m_height = 0;
	m_bitCount = 0;
	m_offBits = 0;
}

void Bmp::procPicture()
{
	readHeader();
	readInfo();
	readRGBQuad();
	return ;
}

void Bmp::readHeader()
{
	int size = sizeof(BITMAPFILEHEADER);
	char* buffer = new char[size];
	readPicture(0, size, buffer);

	BITMAPFILEHEADER *bmphead = (BITMAPFILEHEADER*)buffer;

	if ((bmphead->bfType[0] == 0x42) && 
		(bmphead->bfType[1] == 0x4D))
	{
		m_isbmpfile = true;
	}
	else
	{
		m_isbmpfile = false;
	}

	m_bmpsize |= bmphead->bfSize[0];
	m_bmpsize |= bmphead->bfSize[1] << 8;
	m_bmpsize |= bmphead->bfSize[2] << 16;
	m_bmpsize |= bmphead->bfSize[3] << 24;

	m_offBits |= bmphead->bfOffBits[0];
	m_offBits |= bmphead->bfOffBits[1] << 8;
	m_offBits |= bmphead->bfOffBits[2] << 16;
	m_offBits |= bmphead->bfOffBits[3] << 24;

	delete[] buffer;

	return ;
}

void Bmp::readInfo()
{
	int size = sizeof(BITMAPINFOHEADER);
	char* buffer = new char[size];
	readPicture(BMP_HEADER_SIZE, size, buffer);

	BITMAPINFOHEADER *bmpinfo = (BITMAPINFOHEADER*) buffer;

	m_infosize |= bmpinfo->biSize[0];
	m_infosize |= bmpinfo->biSize[1] << 8;
	m_infosize |= bmpinfo->biSize[2] << 16;
	m_infosize |= bmpinfo->biSize[3] << 24;

	m_width |= bmpinfo->biWidth[0];
	m_width |= bmpinfo->biWidth[1] << 8;
	m_width |= bmpinfo->biWidth[2] << 16;
	m_width |= bmpinfo->biWidth[3] << 24;

	m_height |= bmpinfo->biHeight[0];
	m_height |= bmpinfo->biHeight[1] << 8;
	m_height |= bmpinfo->biHeight[2] << 16;
	m_height |= bmpinfo->biHeight[3] << 24;

	m_bitCount |= bmpinfo->biBitCount[0];
	m_bitCount |= bmpinfo->biBitCount[1] << 8;

	delete[] buffer;

	return ;
}

void Bmp::readRGBQuad()
{
	int count = 0;
	if (m_bitCount == BMP_DOUBLE_COLOR)
	{
		count = 2;
	}

	if (m_bitCount == BMP_16_COLOR)
	{
		count = 16;
	}

	if (m_bitCount == BMP_256_COLOR)
	{
		count = 256;
	}

	if (m_bitCount == BMP_HIGH_COLOR)
	{

	}

	if (m_bitCount == BMP_TRUE_COLOR)
	{

	}

	int size = sizeof(RGBQUAD) * count;
	char* buffer = new char[size];
	readPicture(BMP_HEADER_SIZE + m_infosize, size, buffer);

	RGBQUAD *rgbquad = (RGBQUAD*) buffer;

	delete[] buffer;
	return ;
}

void Bmp::readPicData()
{

	if (0 == (m_bmpsize / 1023 * 1023))
	{
		int RGBnum = m_bmpsize / sizeof(RGB);
		int size = sizeof(RGB) * RGBnum;
		RGB* buffer = new RGB[RGBnum];
		readPicture(m_offBits, size, (char*)buffer);

		delete[] buffer;
	}
	else
	{
		int count = m_bmpsize / (1023 * 1023);
		for (int index = 0; index < count; index++)
		{
			int RGBnum = (1023 * 1023) / sizeof(RGB);
			int size = sizeof(RGB) * RGBnum;
			RGB* buffer = new RGB[RGBnum];
			readPicture(m_offBits + (1023 * 1023) * index, size, (char*)buffer);

			delete[] buffer;
		}

		int tempSize = m_bmpsize % (1023 * 1023);
		if (tempSize != 0)
		{
			int RGBnum = m_bmpsize / sizeof(RGB);
			int size = sizeof(RGB) * RGBnum;
			RGB* buffer = new RGB[RGBnum];
			readPicture(m_offBits, size, (char*)buffer);

			delete[] buffer;
		}
		
	}

	return ;
}

int Bmp::getBmpSize()
{
	return m_bmpsize;
}

bool Bmp::getIsBmp()
{
	return m_isbmpfile;
}