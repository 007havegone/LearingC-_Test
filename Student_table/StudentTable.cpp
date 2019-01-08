#include "StudentTable.h"
#include <cstring>
#include <iostream>

bool initialize(Student_table & t)
{
	t.first = t.tail = new Student;//设置头节点
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
	n->next = NULL;//初始化新节点
	t.tail->next = n;
	t.tail = n;
	t.size++;
	std::cout << "添加成功学生" << stu.name << "成功" << std::endl;
}

void delStudent(Student_table & t, const char* name)
{
	if (t.size == 0) {
		std::cout << "当前学生表没有成员" << std::endl;
		return;
	}
	int i = 0;
	Student* pre = t.first;//获取头节点
	Student* now = pre->next;//获取首元节点
	while ( now && std::strcmp(now->name, name))
	{
		pre = now;
		now = now->next;
		i++;
		//std::cout << i << ' ';
	}
	if (i >= t.size)
	{
		std::cout << "未找到该同学,删除失败" << std::endl;
		return;
	}
	else {
		std::cout << "删除学生" << name  << "成功" << std::endl;
		pre->next = now->next;
		if (i + 1 == t.size)
		{
			//刚好最后一个,修改尾指针
			t.tail = pre;
		}
		delete now;
		t.size--;
	}
}

void show(const Student_table& t)
{
	if (t.size == 0) {
		std::cout << "该学生表没有学生" << std::endl;
		return;
	}
	else {
		Student *p = t.first;
		std::cout << "学生表信息如下: " << std::endl;
		while (p->next)
		{
			std::cout << "姓名: " << p->next->name << '\t'
				<< "学号: " << p->next->id << '\t'
				<< "班级: " << p->next->cl << std::endl;
			p = p->next;
		}
	}
}
