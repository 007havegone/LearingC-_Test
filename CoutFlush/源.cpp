#include <iostream>
using namespace std;
int main()
{
	cout << hex;
	cout << 12 << endl;
	hex(cout);
	cout << 10 << endl;
	cout << 16 << endl;
	cout.width(10);
	cout << 10 << endl;
	cout << 15 << endl;

	cout << hex;//设置16进制
	cout.width(10);//宽度设为10
	cout << flush;//刷新缓冲区
	//cout.precision(2);//精度设为2
	cout.fill('0');//空白用字符0填充
	cout << 123.1234 << endl;
	double d=23.1234;
	double f=12.12345;
	double g = 1200.123456;
	double h = 12.00;
	double j = 2.0;
	cout << "d = " << d << ", f = " << f << endl;
	cout << g << endl;
	cout.setf(ios_base::showpoint);
	cout << h << endl;
	cout << j << endl;
	return 0;
}