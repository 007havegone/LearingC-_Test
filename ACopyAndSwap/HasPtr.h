#ifndef HASPTR_H_
#define HASPTR_H_
#include <string>
#include <iostream>
class HasPtr
{
public:
	//Ĭ�Ϲ��캯��
	HasPtr(const std::string &s="empty") :pstr(new std::string(s)), i(0) {
		std::cout << "use a default construct" << std::endl;
	};
	//��������
	friend void swap(HasPtr &p1, HasPtr &p2);
	//����������
	HasPtr& operator=(HasPtr p);
	//�ƶ����캯��
	HasPtr(HasPtr &&p)noexcept;
	//�������캯��
	HasPtr(const HasPtr&p);
	//��������
	~HasPtr() {
		delete pstr;	
	}

private:
	std::string *pstr;
	int i;
};


#endif // !HASPTR_H_

