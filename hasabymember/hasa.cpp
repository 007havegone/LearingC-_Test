#include "..\hasAbyinheritance\inheritance.h"
#include "..\hasAbyinheritance\inheritance.h"
#include "hasA.h"
using std::endl;
using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::valarray;
using std::string;

ostream& operator<<(ostream& os, const Student& stu)
{
	os << "This student's name is " << stu.name << endl;
	return os;
}
istream& operator>>(istream& is, Student& stu)
{
	cout << "Enter a new name to this student : ";
	is >> stu.name;
	return is;
}
istream& getline(istream& is, Student & stu)
{
	cout << "Enter a name of student : ";
	getline(is,stu.name);
	return is;
}

void Student::show() const
{
	cout << "Student's name is " << name << endl;
	int size = grades.size();
	if (size > 0)
	{
		cout << "Grades is here:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << "¡¢" << grades[i] << "  ";
			if ((i+1) % 5 == 0)
				cout << endl;
		}
		cout << endl;
	}
	else
		cout << "No grades" << endl;

}

double & Student::operator[](int n)
{
	return grades[n];
}

double Student::operator[](int n) const
{
	return grades[n];
}

