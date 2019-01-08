#ifndef HASPTR_H_
#define HASPTR_H_
#include <string>
#include <iostream>
class HasPtr
{
public:
	//Ĭ�Ϲ��캯��
	HasPtr(const std::string &s = "empty") :pstr(new std::string(s)), i(0) {
		std::cout << "use a default construct" << std::endl;
	};
	//��������
	friend void swap(HasPtr &p1, HasPtr &p2);
	//�ƶ���ֵ����
	HasPtr& operator=(HasPtr&& p)noexcept
	{
		pstr = p.pstr; 
		i = p.i;
		std::cout << "use a move operator" << std::endl;
		p.pstr = nullptr;
		return *this;
	}
	//�ƶ����캯��
	HasPtr(HasPtr && p)noexcept
	{
		pstr = p.pstr;
		i = p.i;
		p.pstr = nullptr;
		std::cout << "use a move construct" << std::endl;
	}
	//�������캯��
	HasPtr(const HasPtr&p);
	//������ֵ�����
	HasPtr& operator=(const HasPtr& p);
	//��������
	~HasPtr() {
		delete pstr;
	}

private:
	std::string *pstr;
	int i;
};


#endif // !HASPTR_H_

