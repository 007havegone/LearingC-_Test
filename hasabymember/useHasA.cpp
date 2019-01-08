#include <iostream>
#include "hasA.h"

int main()
{
	using std::cout;
	using std::endl;

	Student s1;
	s1.show();

	double gra[] = { 99,56,44,23 };
	Student *s2 = new Student("Tom",gra,4);
	(*s2)[1] = 100;

	s2->show();
}