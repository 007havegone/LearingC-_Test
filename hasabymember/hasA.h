#ifndef HASA_H_
#define HASA_H_
#include <iostream>
#include <string>
#include <valarray>
class Student
{
private:
	std::string name;
	std::valarray<double> grades;
public:
	Student() :name("NO NAME"), grades(){}
	Student(const std::string& s, const double*g, int n):name(s), grades(g, n){}
	explicit Student(const std::string& s):name(s),grades(){}
	explicit Student(int n):name("NULLy"),grades(n){}
	Student(const std::string& s, std::valarray<double>& ar) :name(s), grades(ar){}

// friend
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& os, Student& stu);

// getMember
	const std::string& Name()const { return name; };
	void show()const;
	double& operator[](int n);
	double operator[](int n)const;

};
#endif // !HASA_H_
