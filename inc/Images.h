#ifndef __IMAGES_H__
#define __IMAGES_H__

#include <string>
#include <vector>
#include "Picture.h"
#include "Bmp.h"

using namespace std;

enum TYPE
{
	IMAGE_JPG = 0,
	IMAGE_BMP,
	IMAGE_PNG,
	IMAGE_UNKNOWN
};

struct IMAGE
{
	int type;
	string path;
};

class Images
{
public:
	Images();
	~Images();
	void setImages(vector<string> files);
	void procImages();

private:
	vector<string> split(string str, string separator) ;

private:
	vector<IMAGE> m_images;
};

#endif // __IMAGES_H__