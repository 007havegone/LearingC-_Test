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

	cout << hex;//����16����
	cout.width(10);//�����Ϊ10
	cout << flush;//ˢ�»�����
	//cout.precision(2);//������Ϊ2
	cout.fill('0');//�հ����ַ�0���
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