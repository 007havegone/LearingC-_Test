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

status CreatLkList(LinkList &L, int n);							//ǰ�巨����n��Ԫ�ص�����
status InsertLkList(LinkList &L, int i, ElemType e);			//�ڵ�i��λ�ò���Ԫ��e
status DeleteLkList(LinkList &L, int i);						//ɾ����i��Ԫ��
status DeleteLkList(LinkList &L, ElemType mmin, ElemType mmax);//ɾ������(mmin��mmax)��Ԫ��
status DestoryLkList(LinkList &L);								//��������
int FindOrInsert(LinkList &L, ElemType x);						//����Ԫ�ط���λ��û�н���������λ��
LNode* reverseList(LinkList &L, int flag);						//�ݹ鷴ת����
std::ostream& operator<<(std::ostream& os, LinkList L);			//����<<��ӡ����
#endif // !LINKEDLIST