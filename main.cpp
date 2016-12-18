#include <stdlib.h>
#include "File.h"
#include "Images.h"
#include <string>
using namespace std;

int main(int argc, char * argv[])
{
	//string path = "/home/dapper/图片/background/sky37.jpg";
	File sfile("/home/dapper/图片/background/sky37.bmp");

	Images image;
	image.setImages(sfile.getFiles());
	image.procImages();
	return 0;
}