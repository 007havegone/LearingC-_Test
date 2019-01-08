#include "StudentTable.h"
#include <iostream>
int main()
{
	using std::cout;
	using std::endl;
	Student_table table;
	initialize(table);
	cout << table.size << endl;
	Student s1 = { "Tom","17251102145","1" };
	Student s2 = { "Jim","17555123552","2" };
	Student s3 = { "Mike","1314553123","3" };
	addStudent(table, s1);
	addStudent(table, s2);
	addStudent(table, s3);
	show(table);

	delStudent(table, "Jom");
	delStudent(table, "Mike");
	show(table);
}