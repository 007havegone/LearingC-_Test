#ifndef RENAMEFILE_H_
#define RENAMEFILE_H_
#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>
#include <direct.h>//_getcwdͷ�ļ�
class RenameFile
{
public:
	RenameFile();
	void updateTime();
	void showmdir();
	static int num;
	std::string getDirName();
private:
	char mdir[MAX_PATH];//����Ŀ¼
	std::string mstr_time;//ʱ�䴮
	std::string getJpgName();
		
	

	
};
#endif // !RENAMEFILE_H_

