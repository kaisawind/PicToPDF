#include "Bmp.h"

Bmp::Bmp(string image) : Picture(image)
{
	m_isbmpfile =  false;
	m_bmpsize = 0;
}

Bmp::Bmp() : Picture()
{
	m_isbmpfile =  false;
	m_bmpsize = 0;
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

	BITMAPFILEHEADER *bmphead = (BITMAPFILEHEADER*) buffer;

	if (bmphead->bfType == BMPTYPE)
	{
		m_isbmpfile = true;
	}
	else
	{
		m_isbmpfile = false;
	}
	printf("bfType:%x \n", bmphead->bfType);
	printf("m_isbmpfile:%d \n", m_isbmpfile);
	m_bmpsize = SWAP_32(bmphead->bfSize);

	m_offBits = SWAP_32(bmphead->bfOffBits);

	printf("m_bmpsize:%d m_offBits:%d\n", m_bmpsize, m_offBits);

	delete[] buffer;

	return ;
}

void Bmp::readInfo()
{
	int size = sizeof(BITMAPINFOHEADER);
	char* buffer = new char[size];
	readPicture(BMP_HEADER_SIZE, size, buffer);

	BITMAPINFOHEADER *bmpinfo = (BITMAPINFOHEADER*) buffer;

	m_infosize = SWAP_32(bmpinfo->biSize);
	m_width = SWAP_32(bmpinfo->biWidth);
	m_height = SWAP_32(bmpinfo->biHeight);
	m_bitCount = SWAP_16(bmpinfo->biBitCount);

	printf("m_infosize:%d m_width:%d m_height:%d m_bitCount:%d\n", m_infosize, m_width, m_height, m_bitCount);

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