#include "Jpg.h"
#include <string.h>

Jpg::Jpg(string image) : Picture(image)
{

}

Jpg::Jpg() : Picture()
{
	
}

Jpg::~Jpg()
{

}

void Jpg::procPicture()
{
	
	char buffer[2] = {0};
	int bufPos = 0;

	while (1) 
	{
		readPicture(bufPos, 2, buffer);
		printf("%s %d %02x%02x\n", __func__, __LINE__, buffer[0] & 0xFF, buffer[1] & 0xFF);
		switch (buffer[1] & 0xFF) 
		{
		case SOI:
			bufPos = 2;
			break;
		case APP0:
		{
			bufPos += 2;
			readPicture(bufPos, 2, buffer);
			int length = 0;
			length |= buffer[1];
			length |= buffer[0] << 8;

			printf("%s %d APP0 length:%d\n", __func__, __LINE__, length);

			char app0[length - 2] = {0};
			readPicture(bufPos + 2, bufPos + length, app0);

			bufPos += length;
			break;
		}
		case COM:
		{
			bufPos += 2;
			readPicture(bufPos, 2, buffer);
			int length = 0;
			length |= buffer[1];
			length |= buffer[0] << 8;

			printf("%s %d COM length:%d\n", __func__, __LINE__, length);

			char com[length - 2] = {0};
			readPicture(bufPos + 2, bufPos + length, com);

			printf("%s \n", com);

			bufPos += length;
			break;
		}
		case DQT:
		{
			bufPos += 2;
			readPicture(bufPos, 2, buffer);
			int length = 0;
			length |= buffer[1];
			length |= buffer[0] << 8;

			printf("%s %d DQT length:%d\n", __func__, __LINE__, length);

			char dqt[length - 2] = {0};
			readPicture(bufPos + 2, bufPos + length, dqt);

			bufPos += length;
			break;
		}
		case SOF0:
		{
			bufPos += 2;
			readPicture(bufPos, 2, buffer);
			int length = 0;
			length |= buffer[1];
			length |= buffer[0] << 8;

			printf("%s %d DQT length:%d\n", __func__, __LINE__, length);

			char dqt[length - 2] = {0};
			readPicture(bufPos + 2, bufPos + length, dqt);

			bufPos += length;
			break;
		}
		default:
			goto exit;
			break;
		}

	}

exit:
	return ;
}