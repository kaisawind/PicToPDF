#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>

using namespace std;

class File
{
public:
	File();
	File(string path);
	~File();
	void setPath(string path);

private:
	void procDirectory(string path);
	bool procFilePath(string path);

private:
	vector<string> m_files;
};

#endif //__FILE_H__