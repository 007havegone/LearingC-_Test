#include "StudentTable.h"
#include <cstring>
#include <iostream>

bool initialize(Student_table & t)
{
	t.first = t.tail = new Student;//����ͷ�ڵ�
	t.first->next = NULL;
	t.size = 0;
	return true;
}

void addStudent(Student_table & t, const Student & stu)
{
	Student *n = new Student;
	strcpy(n->name, stu.name);
	strcpy(n->id, stu.id);
	strcpy(n->cl, stu.cl);
	n->next = NULL;//��ʼ���½ڵ�
	t.tail->next = n;
	t.tail = n;
	t.size++;
	std::cout << "��ӳɹ�ѧ��" << stu.name << "�ɹ�" << std::endl;
}

void delStudent(Student_table & t, const char* name)
{
	if (t.size == 0) {
		std::cout << "��ǰѧ����û�г�Ա" << std::endl;
		return;
	}
	int i = 0;
	Student* pre = t.first;//��ȡͷ�ڵ�
	Student* now = pre->next;//��ȡ��Ԫ�ڵ�
	while ( now && std::strcmp(now->name, name))
	{
		pre = now;
		now = now->next;
		i++;
		//std::cout << i << ' ';
	}
	if (i >= t.size)
	{
		std::cout << "δ�ҵ���ͬѧ,ɾ��ʧ��" << std::endl;
		return;
	}
	else {
		std::cout << "ɾ��ѧ��" << name  << "�ɹ�" << std::endl;
		pre->next = now->next;
		if (i + 1 == t.size)
		{
			//�պ����һ��,�޸�βָ��
			t.tail = pre;
		}
		delete now;
		t.size--;
	}
}

void show(const Student_table& t)
{
	if (t.size == 0) {
		std::cout << "��ѧ����û��ѧ��" << std::endl;
		return;
	}
	else {
		Student *p = t.first;
		std::cout << "ѧ������Ϣ����: " << std::endl;
		while (p->next)
		{
			std::cout << "����: " << p->next->name << '\t'
				<< "ѧ��: " << p->next->id << '\t'
				<< "�༶: " << p->next->cl << std::endl;
			p = p->next;
		}
	}
}
