#include "inheritance.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

const string& Student::getName()const
{
	return (const string&)*this;
}

ostream& operator<<(ostream& os, const Student& stu)
{
	os << "Student's name is " << (const string&)stu << endl;//˽�м̳�ͨ��ǿ��ת����Ȼ�����string�����������
	stu.gra_out(os);
	return os;
}
istream& operator>>(istream& is, Student& stu)
{
	is >> (string&)stu;//������ε��û������Ԫ����
	return is;
}
istream& getline(istream& is, Student& stu)
{
	getline(is, (string&)stu);
	return is;
}
double& Student::operator[](int n)
{
	//return Grades::operator[](n);
	return ((Grades&)(*this))[n];//ǿ��ת�������Grades�����غ��[]�����
}
double Student::operator[](int n)const
{
	return Grades::operator[](n);
}
void Student::show()const
{
	cout << "Student'name is " << (const string&)*this << endl;
	gra_out(cout);
}
void Student::gra_out(ostream& os)const
{
	int size = Grades::size();
	if (size > 0)
	{
		cout << (const string&)*this << "'s grades is here : " << endl;
		for (int i = 0; i < size; i++)
			cout << i + 1 << "��" << Grades::operator[](i) << "  ";
		cout << endl;
	}
	else
		cout << "No grades" << endl;
}