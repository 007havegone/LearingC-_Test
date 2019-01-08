#ifndef HASPTR_H_
#define HASPTR_H_
#include <string>
#include <iostream>
class HasPtr
{
public:
	//默认构造函数
	HasPtr(const std::string &s="empty") :pstr(new std::string(s)), i(0) {
		std::cout << "use a default construct" << std::endl;
	};
	//交换函数
	friend void swap(HasPtr &p1, HasPtr &p2);
	//拷贝并交换
	HasPtr& operator=(HasPtr p);
	//移动构造函数
	HasPtr(HasPtr &&p)noexcept;
	//拷贝构造函数
	HasPtr(const HasPtr&p);
	//析构函数
	~HasPtr() {
		delete pstr;	
	}

private:
	std::string *pstr;
	int i;
};


#endif // !HASPTR_H_

