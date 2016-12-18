#ifndef __PICTURE_H__
#define __PICTURE_H__

#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <errno.h>
#include <iostream>
#include <bitset>
#include "type.h"

using namespace std;

class Picture
{
public:
	Picture();
	~Picture();
	Picture(string image);
	void setPicture(string image);
	void procPicture();
	void readPicture(int from , int size, char* buffer);
	
private:
	string m_pic;
};

#endif //__PICTURE_H__