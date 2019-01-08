#include "BitTree.h"
#include <iostream>
#include <stack>
#include <map>
#include <queue>
using namespace std;
void CreateBitTree(BitTree & T)
{
	int c;
	cin >> c;
	if (c == -1)
		T = nullptr;
	else
	{
		T = new BitNode;
		T->data = c;
		CreateBitTree(T->lchild);
		CreateBitTree(T->rchild);
	}
}
bool BitTreeEmpty(BitTree t)
{
	return t==NULL;
}
void CopyTree(BitTree t1, BitTree & t2)
{
	if (!t1)
	{
		t2 = nullptr;
	}
	else
	{
		t2 = new BitNode;
		t2->data = t1->data;
		CopyTree(t1->lchild, t2->lchild);
		CopyTree(t1->rchild, t2->rchild);
	}
}
void DestoryTree(BitTree & t)
{
	if (t){
		DestoryTree(t->lchild);
		DestoryTree(t->rchild);
		delete[] t;
		t = nullptr;
	}
}
int TreeDepth(BitTree t)
{
	if (!t)
		return 0;
	else
	{
		int a = TreeDepth(t->lchild);
		int b = TreeDepth(t->rchild);
		return a > b ? a + 1 : b + 1;
	}
}
int NodeCount(BitTree t)
{
	if (!t)
	{
		return 0;
	}
	else
	{
		return NodeCount(t->lchild) + NodeCount(t->rchild) + 1;
	}
}
void EchangeLRchile(BitTree & t)
{
	if(t)
	{
		EchangeLRchile(t->lchild);
		EchangeLRchile(t->rchild);
		BitNode *temp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = temp;
	}
}
bool equal(BitTree t1, BitTree t2)
{
	if (!t1 && !t2)//Ϊ�գ����
	{
		return true;
	}
	//����һ��Ϊ��
	else if (!t1 || !t2)
		return false;
	if(t1->data != t2->data)//���ڵ㲻ͬ����false
		return false;
	//���ڵ���ͬ���������������Ƿ����
	return equal(t1->lchild, t2->lchild) && equal(t1->rchild, t2->rchild);
}
BitNode * getLoca(BitTree t, TElemType e)
{
	if (t)
	{
		if (t->data == e)
			return t;
		BitNode* t1 = getLoca(t->lchild, e);
		BitNode* t2 = getLoca(t->rchild, e);
		if (t1)
			return t1;
		else if (t2)
			return t2;
		else
			return NULL;
	}
	else
		return NULL;
}

bool AddNode(BitTree & t,TElemType par, TElemType e, LOC loc)
{
	if (t)
	{
		return false;//����ʧ��
	}
	BitNode* p = getLoca(t, par);
	if (!p)
		cout << "not such parents" << endl;
	if (loc == LEFT && !p->lchild)
	{
		BitNode* ch = new BitNode;
		ch->data = e;
		ch->lchild = ch;ch->rchild = NULL;
	}
	else if (loc == RIGHT && !p->rchild)
	{
		BitNode* ch = new BitNode;
		ch->rchild = ch; ch->lchild = NULL;
	}
	else
	{
		return false;
	}
	return true;

}

void InThreading(BitTree  t, BitTree &pre)
{
	if (t)
	{
		InThreading(t->lchild, pre);//����������������
		//�������ڵ�
		if (!t->lchild)
		{
			t->lchild = pre;
			t->LTag = 1;
		}
		else { t->LTag = 0; }
		if (!pre->rchild)
		{
			pre->RTag = 1;
			pre->rchild = t;
		}
		else { pre->RTag = 0; }
		pre = t;
		InThreading(t->rchild, pre);//����������
	}
}

void InOrderThreading(BitTree t, BitTree & head)//��ͷ��������������
{
	head = new BitNode;//�½�ͷ���
	head->LTag = 0;//ͷ��������ӣ�������ǿգ�ָ������
	head->RTag = 1;//��ͷ�ڵ�������
	head->rchild = head;//��ʼ��Ϊ�Լ�
	if(!t)head->lchild = head;//����
	else
	{
		head->lchild = t;//���ǿգ�ͷ���������Ϊ�����
		BitNode* pre = head;//����ֱ����Ϊǰ�������ܻ��޸�head��ָ
		InThreading(t, pre);//ͷ�����Ϊ��ʼǰ��
		pre->rchild = head;//�����������Ϊͷ���
		pre->RTag = 1;
		head->rchild = pre;//ͷ�����������Ϊ���һ�����ʽ��

	}
}

//ǰ�����Ϊ������
void LessThan(BitTree t, TElemType e)
{
	if (t)
	{
		LessThan(t->lchild, e);//�ȵ�������Ѱ��
		//�����ǰ��e��ֱ���˳������ý�������������
		if (t->data >= e)
			return;
		cout << t->data << " ";
		LessThan(t->rchild, e);
	}
}
//ǰ��Ϊ������
void GreatThan(BitTree t, TElemType e)
{
	if (t)
	{
		GreatThan(t->rchild, e);//������������
		if (t->data <= e)//�������e��ҪС�����ý�������������
			return;
		cout << t->data << " ";
		GreatThan(t->lchild, e);
	}
}

int	LeavesCount(BitTree t)//�����������
{
	if (t)
	{
		if (!t->lchild && !t->rchild)
			return 1;
		else
			return LeavesCount(t->lchild) + LeavesCount(t->rchild);
	}
	return 0;
}

int getMaxWidth(BitTree t)
{
	if (!t)return 0;//���������Ϊ0
	BitNode *p = nullptr;
	int max = 1;/*�����*/
	int cur= 1;/*��ǰ����*/
	int next = 0;/*��һ����*/
	int i = 0;/*��¼��ǰ����ʽ����*/
	queue<BitNode*> que;
	que.push(t);//��ʼ������
	while (!que.empty())//��ǰ���δ������
	{
		p = que.front();
		que.pop();
		i++;
		//�����һ���н�㣬ѹ��ͬʱ������+1
		if (p->lchild) { next++; que.push(p->lchild); }
		if (p->rchild) { next++; que.push(p->rchild); };
		//��ǰ�����ѷ������
		if (i == cur)
		{
			i = 0;//���ü�����
			if (next > max)//��ϸ�����
				max = next;
			cur = next;//���µ�ǰ��
			next = 0;//������һ�����
		}
	}
	return max;
}

int getTD1Count(BitTree t)
{
	if (!t)
		return 0;
	BitNode *p;
	queue<BitNode*> que;
	int sum = 0;
	que.push(t);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (!p->lchild && !p->rchild)
			continue;
		int c = 0;
		if (p->lchild) {
			que.push(p->lchild);
			c++;
		}
		if (p->rchild) {
			que.push(p->rchild);
			c++;
		}
		if (c == 1)
			sum++;
	}
	return sum;
}

void ShowDepthestPath(BitTree t)
{
	BitTree p = t, l[MAXDEAPTH], s[MAXDEAPTH];//p��¼��ǰջ��l�ջ��sΪ����ջ
	int top = 0, longest = 0;//top�α�ָ��ջ��
	int tag[MAXDEAPTH];//��Ƿ��ʼ�¼
	while (p || top > 0)//δ��ջ�ף�����ջ�ǿ�
	{
		while (p)//������������ֱ�����ڵ�
		{
			s[++top] = p;
			tag[top] = 1;//��Ǹ��ڵ�
			p = p->lchild;
		}
		if (tag[top] == 2)//���ʸ��ڵ�
		{
			if(!s[top]->lchild&&!s[top]->rchild)//������ڵ�
				if (top > longest)//�Ƚ��Ƿ����·��
				{
					for (int i = 1; i <= top; i++)l[i] = s[i];//�洢·��
					longest = top;//���³���
				}
			top--;//����ջ
			p = nullptr;
		}
		else if(tag[top]==1)
		{
			tag[top] = 2;//��¼+1
			p = s[top]->rchild;//����1��������β�ݹ鲻�ý�ջ

		}
	}
	int i = 1;
	cout << "The max len path to root: ";
	while (i <= longest)
	{
		cout << l[i]->data << " ";
		i++;
	}
	cout << endl;
}

void GetPath(BitTree t, TElemType path[], int pathlen)
{
	if (!t->lchild && !t->rchild)//���ʵ�Ҷ�ڵ�
	{
		cout << " " << t->data << "�����ڵ��·�� " << t->data << " ";
		for (int i = pathlen -1; i >= 0; i--)
			cout << path[i] << " ";
		cout << endl;
	}
	else//δ����Ҷ�ڵ㣬��¼���ڵ㣬�ݹ���������
	{
		path[pathlen] = t->data;
		pathlen++;
		GetPath(t->lchild, path, pathlen);
		GetPath(t->rchild, path, pathlen);

	}
}


void InOrderTraverse_Thr(BitTree head)
{
	BitNode *p = head->lchild;//ָ����ڵ�
	while(p!=head)//�ǿ�����δ���������һ�����
	{
		//����������
		while (!p->LTag)
			p = p->lchild;//�ﵽ�����½�
		cout << p->data << " ";//���������¶˵�
		while (p->RTag && p->rchild != head)//����������ֱ�������ڵ㣬��ζ�ŷ��ʵ����һ�����
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;//����p��������
	}
}

void PreOrderTraverse(BitTree T)
{
	if (T)
	{
		cout << T->data << " ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BitTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data << " ";
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BitTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data << " ";
	}
}

void RePreOrderTraverse(BitTree T)
{
	stack<BitNode*> sta;
	BitNode *p = T;
	BitNode *t;//��ʱ�洢����Ԫ��
	while (p || !sta.empty())
	{
		if (p)
		{
			cout << p->data << " ";//�����ǰ�ڵ�
			sta.push(p);//���浱ǰ���
			p = p->lchild;//����������
		}
		else//�������������
		{
			t = sta.top();//�ص��ϲ���
			sta.pop();//�����ò�
			p = t->rchild;//����������
		}
	}

}

void ReInOrderTraverse(BitTree T)
{
	stack<BitNode*> sta;
	BitNode *p = T;
	BitNode *q;
	while (p || !sta.empty())//��ǰ����ջδ��
	{
		if (p)
		{
			sta.push(p);//���浱ǰ���
			p = p->lchild;//����������
		}
		else//�������������
		{
			q=sta.top();//��ȡ��һ��
			sta.pop();//����
			cout << q->data << " ";//���ʸ��ڵ�
			p = q->rchild;//����������
		}
	}
}

void RePostOrderTraverse(BitTree T)
{
	stack<BitNode*> sta;
	map<BitNode*,int> tag;
	BitNode* p = T;
	BitNode* t;
	while (p || !sta.empty())
	{
		if (p)
		{
			tag[p] = 1;
			sta.push(p);//���浱ǰ��
			p = p->lchild;//����������
		}
		else//�������������
		{
			t = sta.top();
			if (!t->rchild)//û��������,˵���������ն�
			{
				cout << t->data << " ";//��ӡ�ն�
				sta.pop();
				p = t->rchild;
			}
			else {//�Ǹ��ڵ�
				if (tag[t] == 1)
				{
					tag[t] = 2;
					p=t->rchild;//β�ݹ飬����ѹ��
				}
				else if(tag[t]==2)
				{
					cout << t->data << " ";
					sta.pop();//��ջ���ص���һ��
					p = NULL;
				}
			}
		}
	}
}
