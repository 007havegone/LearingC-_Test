#ifndef RENAMEFILE_H_
#define RENAMEFILE_H_
#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>
#include <direct.h>//_getcwd头文件
class RenameFile
{
public:
	RenameFile();
	void updateTime();
	void showmdir();
	static int num;
	std::string getDirName();
private:
	char mdir[MAX_PATH];//工作目录
	std::string mstr_time;//时间串
	std::string getJpgName();
		
	

	
};
#endif // !RENAMEFILE_H_

