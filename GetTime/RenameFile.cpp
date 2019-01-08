#include "RenameFile.h"
#include <cstring>
#include <sstream>
using namespace std;
int RenameFile::num = 0;
RenameFile::RenameFile()
{
	_getcwd(mdir, MAX_PATH);//获取当前工作目录
	//GetModuleFileName(NULL,(LPWSTR)mdir, sizeof(mdir));
	/*int i = strlen(mdir) - 1;
	while (i >= 0)
	{
		if (mdir[i] == '\\')
			break;
		i--;
	}
	mdir[i] = '\0';*/
}

std::string RenameFile::getDirName()
{
	stringstream s;
	string name;
	s << mdir << "\\CZX" << mstr_time << ++num;
	s >> name;
	cout << name;
	return name;
}

std::string RenameFile::getJpgName()
{
	return std::string();
}

void RenameFile::updateTime()
{
	char str_time[100];
	struct tm *local_time = NULL;
	time_t utc_time;
	utc_time = time(NULL);
	local_time = localtime(&utc_time);
	strftime(str_time, sizeof(str_time), "%Y%m%d%H%M%S", local_time);
	mstr_time = mstr_time + str_time;
}

void RenameFile::showmdir()
{
	cout << mdir << endl;
}
