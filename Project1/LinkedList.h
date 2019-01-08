#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int status;
typedef  struct  LNode
{
	ElemType data;
	LNode *next;
} LNode, *LinkList;

status CreatLkList(LinkList &L, int n);							//前插法创建n个元素的链表
status InsertLkList(LinkList &L, int i, ElemType e);			//在第i个位置插入元素e
status DeleteLkList(LinkList &L, int i);						//删除第i个元素
status DeleteLkList(LinkList &L, ElemType mmin, ElemType mmax);//删除区间(mmin，mmax)的元素
status DestoryLkList(LinkList &L);								//销毁链表
int FindOrInsert(LinkList &L, ElemType x);						//查找元素返回位序没有将其插入合适位置
LNode* reverseList(LinkList &L, int flag);						//递归反转链表
std::ostream& operator<<(std::ostream& os, LinkList L);			//重载<<打印链表
#endif // !LINKEDLIST