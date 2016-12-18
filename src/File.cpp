#include "File.h"

File::File()
{
}

File::File(string path)
{
	setPath(path);
}

File::~File()
{
	m_files.clear();
}

void File::setPath(string path)
{
	if (!procFilePath(path))
	{
		procDirectory(path);
	}

	return ;
}

void File::procDirectory(string path)
{
	DIR *dir;  
    struct dirent *ptr;  
    char base[1000];  
   
    if ((dir = opendir(path.c_str())) == NULL)  
    {  
        perror("Open dir error...");  
        exit(1);  
    }  
   
    while ((ptr = readdir(dir)) != NULL)  
    {  
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir  
            continue; 

        switch (ptr->d_type)
        {
    	case DT_REG:	//This is a directory.
        	m_files.push_back(ptr->d_name); 
        	break;
        case DT_BLK:	//This is a block device.
        case DT_CHR:	//This is a character device.
        case DT_FIFO:	//This is a named pipe (FIFO).
        case DT_SOCK:	//This is a UNIX domain socket.
        	break;
        case DT_DIR:	//This is a directory.
        	procDirectory(ptr->d_name);
        	break;
        default:
        	break;
        }
         
    }  
    closedir(dir);
	return ;
}

bool File::procFilePath(string path)
{
	bool ret = false;
	//R_OK      测试读许可权  
	//W_OK      测试写许可权  
	//X_OK      测试执行许可权  
	//F_OK      测试文件是否存在
	if (access(path.c_str(), F_OK) == 0)
	{
		m_files.push_back(path);
		ret = true;
	}
	return ret;
}

vector<string> File::getFiles()
{
	return m_files;
}