#ifndef STUDENT_H_
#define STUDENT_H_
typedef struct Student
{
	char name[9];
	char id[12];
	char cl[9];
	Student* next;
}Student;
typedef struct
{
	int size;
	Student* first;
	Student* tail;
}Student_table;

bool initialize(Student_table & t);
void addStudent(Student_table & t, const Student& stu);
void delStudent(Student_table & t, const char* id);
void show(const Student_table &t);
#endif // !STUDENT_H_
