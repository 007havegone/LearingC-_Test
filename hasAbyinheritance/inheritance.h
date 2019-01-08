#ifndef INHERITANCE_H_
#define INHERITANCE_H_
#include <string>
#include <valarray>
#include <iostream>
class Student
	//˽�м̳У�ӵ�г�Ա���г�Ա��������Ϊ�����ӿڣ�����˽��
	:private std::string, private std::valarray<double>//Ĭ����˽�м̳�
{
private:
	typedef std::valarray<double> Grades;
	void gra_out(std::ostream&)const;
public:
	Student() : std::string("NO NAME"), Grades() {}
	Student(const std::string& n,int m) : std::string(n), Grades(m) {}
	Student(const std::string& n, Grades& g) : std::string(n), Grades(g) {}
	Student(const std::string& n, const double*g, int m)
		: std::string(n), Grades(g, m) {}
	explicit Student(const std::string& s)
		: std::string(s), Grades() {}
	explicit Student(int n)
		: std::string("NO NAME"), Grades() {}
	// friends
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	// getMenber
	void show()const;
	const std::string& getName()const;
	double& operator[](int n);
	double operator[](int n)const;


};

#endif // !INHERITANCE
