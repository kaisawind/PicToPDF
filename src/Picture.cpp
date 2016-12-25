#include "Picture.h"

Picture::Picture()
{
	m_pic = "";
}

Picture::~Picture()
{

}

Picture::Picture(string image)
{
	m_pic = image;
}

void Picture::setPicture(string image)
{
	m_pic = image;

	return ;
}

void Picture::procPicture()
{
	return ;
}

void Picture::readPicture(int from , int size, char* buffer)
{
	ifstream file(m_pic, ios::in|ios::binary);

	if (!file)
	{
		perror("Open Picture error..."); 
		return ;
	}

	int filebeg = file.tellg();
	file.seekg (0, ios::end); 
	int fileend = file.tellg();
	int totalsize = fileend - filebeg;

	if (from >= totalsize)
	{
		return ;
	}

	if (size > totalsize)
	{
		size = totalsize;
	}

    file.seekg (from, ios::beg);   
    file.read (buffer, size); 

	file.close();
	return ;
}