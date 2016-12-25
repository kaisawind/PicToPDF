#include "Images.h"

Images::Images()
{

}

Images::~Images()
{
	m_images.clear();
}

void Images::setImages(vector<string> files)
{
	for (auto file : files)
	{
		vector<string> folders = split(file, "/");
		int folderslen = folders.size();
		string fileName = folders[folderslen - 1];
		vector<string> extensions = split(fileName, ".");

		int extenlen = extensions.size();

		string extension = extensions[extenlen - 1];

		IMAGE image;

		if (extension == "jpg")
		{
			image.type = IMAGE_JPG;
			image.path = file;
			m_images.push_back(image);
		}

		if (extension == "bmp")
		{
			image.type = IMAGE_BMP;
			image.path = file;
			m_images.push_back(image);
		}

		if (extension == "jepg")
		{
			image.type = IMAGE_JPG;
			image.path = file;
			m_images.push_back(image);
		}

		if (extension == "png")
		{
			image.type = IMAGE_PNG;
			image.path = file;
			m_images.push_back(image);
		}
		
	}
	return ;
}

void Images::procImages()
{
	for (auto image : m_images)
	{
		switch (image.type)
		{
		case IMAGE_JPG:
		{
			Bmp* bmp = new Bmp(image.path);
			
			bmp->procPicture();
		}
			break;
		case IMAGE_BMP:
		{
			Bmp* bmp = new Bmp(image.path);
			
			bmp->procPicture();
		}
			break;
		case IMAGE_PNG:
			break;
		default:
			break;
		}
	}
	return ;
}

vector<string> Images::split(string str, string separator)  
{  
    vector<string> result;  
    int cutAt = 0;  
    while( (cutAt = str.find_first_of(separator)) != str.npos )  
    {  
        if(cutAt > 0)  
        {  
            result.push_back(str.substr(0, cutAt));  
        }
        else
        {  
            result.push_back("");  
        }  
        str = str.substr(cutAt + 1);  
    } 

    if(str.length() > 0)  
    {  
        result.push_back(str);  
    }
    else
    {  
        result.push_back("");  
    }

    return result;  
}