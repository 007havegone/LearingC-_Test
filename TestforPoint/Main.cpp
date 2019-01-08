#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
int main()
{
	extern char p[];//不同文件，数组是数组，指针是指针，不可以交叉使用
	extern const char *g;
	printf("%s", p);
	printf("%s", g);
	cout << endl;
	const time_t t = time(0);
	cout << ctime(&t) << endl;
	return 0;
}