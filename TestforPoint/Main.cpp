#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
int main()
{
	extern char p[];//��ͬ�ļ������������飬ָ����ָ�룬�����Խ���ʹ��
	extern const char *g;
	printf("%s", p);
	printf("%s", g);
	cout << endl;
	const time_t t = time(0);
	cout << ctime(&t) << endl;
	return 0;
}