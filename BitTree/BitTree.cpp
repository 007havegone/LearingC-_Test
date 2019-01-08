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
	if (!t1 && !t2)//为空，相等
	{
		return true;
	}
	//其中一个为空
	else if (!t1 || !t2)
		return false;
	if(t1->data != t2->data)//根节点不同返回false
		return false;
	//根节点相同，返回左右子树是否相等
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
		return false;//空树失败
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
		InThreading(t->lchild, pre);//中序线索话左子树
		//线索根节点
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
		InThreading(t->rchild, pre);//线索右子树
	}
}

void InOrderThreading(BitTree t, BitTree & head)//带头结点的中序线索化
{
	head = new BitNode;//新建头结点
	head->LTag = 0;//头结点有左孩子，如果树非空，指向树根
	head->RTag = 1;//将头节点线索化
	head->rchild = head;//初始化为自己
	if(!t)head->lchild = head;//空树
	else
	{
		head->lchild = t;//树非空，头结点左子树为根结点
		BitNode* pre = head;//不能直接作为前驱，可能会修改head的指
		InThreading(t, pre);//头结点作为开始前驱
		pre->rchild = head;//最后结点右线索为头结点
		pre->RTag = 1;
		head->rchild = pre;//头结点有线索设为最后一个访问结点

	}
}

//前提该树为有序树
void LessThan(BitTree t, TElemType e)
{
	if (t)
	{
		LessThan(t->lchild, e);//先到左子树寻找
		//如果当前比e大，直接退出，不用进入右子树查找
		if (t->data >= e)
			return;
		cout << t->data << " ";
		LessThan(t->rchild, e);
	}
}
//前提为有序树
void GreatThan(BitTree t, TElemType e)
{
	if (t)
	{
		GreatThan(t->rchild, e);//到右子树查找
		if (t->data <= e)//如果根比e还要小，不用进入左子树查找
			return;
		cout << t->data << " ";
		GreatThan(t->lchild, e);
	}
}

int	LeavesCount(BitTree t)//类似先序遍历
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
	if (!t)return 0;//空树，宽度为0
	BitNode *p = nullptr;
	int max = 1;/*最大宽度*/
	int cur= 1;/*当前层宽度*/
	int next = 0;/*下一层宽度*/
	int i = 0;/*记录当前层访问结点数*/
	queue<BitNode*> que;
	que.push(t);//初始化队列
	while (!que.empty())//当前结点未遍历完
	{
		p = que.front();
		que.pop();
		i++;
		//如果下一层有结点，压入同时计数器+1
		if (p->lchild) { next++; que.push(p->lchild); }
		if (p->rchild) { next++; que.push(p->rchild); };
		//当前层数已访问完成
		if (i == cur)
		{
			i = 0;//重置计数器
			if (next > max)//更细最大宽度
				max = next;
			cur = next;//更新当前层
			next = 0;//重置下一层个数
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
	BitTree p = t, l[MAXDEAPTH], s[MAXDEAPTH];//p记录当前栈。l最长栈，s为工作栈
	int top = 0, longest = 0;//top游标指向栈顶
	int tag[MAXDEAPTH];//标记访问记录
	while (p || top > 0)//未到栈底，工作栈非空
	{
		while (p)//遍历左子树，直至根节点
		{
			s[++top] = p;
			tag[top] = 1;//标记根节点
			p = p->lchild;
		}
		if (tag[top] == 2)//访问根节点
		{
			if(!s[top]->lchild&&!s[top]->rchild)//到达根节点
				if (top > longest)//比较是否是最长路径
				{
					for (int i = 1; i <= top; i++)l[i] = s[i];//存储路径
					longest = top;//更新长度
				}
			top--;//根退栈
			p = nullptr;
		}
		else if(tag[top]==1)
		{
			tag[top] = 2;//记录+1
			p = s[top]->rchild;//进入1右子树，尾递归不用进栈

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
	if (!t->lchild && !t->rchild)//访问到叶节点
	{
		cout << " " << t->data << "到根节点的路径 " << t->data << " ";
		for (int i = pathlen -1; i >= 0; i--)
			cout << path[i] << " ";
		cout << endl;
	}
	else//未到达叶节点，记录根节点，递归左右子树
	{
		path[pathlen] = t->data;
		pathlen++;
		GetPath(t->lchild, path, pathlen);
		GetPath(t->rchild, path, pathlen);

	}
}


void InOrderTraverse_Thr(BitTree head)
{
	BitNode *p = head->lchild;//指向根节点
	while(p!=head)//非空树或未遍历到最后一个结点
	{
		//进入左子树
		while (!p->LTag)
			p = p->lchild;//达到最左下角
		cout << p->data << " ";//访问最左下端点
		while (p->RTag && p->rchild != head)//往有线索找直到到根节点，意味着访问到最后一个结点
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;//进入p的右子树
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
	BitNode *t;//临时存储弹出元素
	while (p || !sta.empty())
	{
		if (p)
		{
			cout << p->data << " ";//输出当前节点
			sta.push(p);//保存当前结点
			p = p->lchild;//进入左子树
		}
		else//左子树遍历完成
		{
			t = sta.top();//回到上层结点
			sta.pop();//弹出该层
			p = t->rchild;//进入右子树
		}
	}

}

void ReInOrderTraverse(BitTree T)
{
	stack<BitNode*> sta;
	BitNode *p = T;
	BitNode *q;
	while (p || !sta.empty())//当前树或栈未空
	{
		if (p)
		{
			sta.push(p);//保存当前结点
			p = p->lchild;//进入左子树
		}
		else//左子树访问完成
		{
			q=sta.top();//获取上一层
			sta.pop();//弹出
			cout << q->data << " ";//访问根节点
			p = q->rchild;//进入右子树
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
			sta.push(p);//保存当前层
			p = p->lchild;//进入左子树
		}
		else//左子树遍历完成
		{
			t = sta.top();
			if (!t->rchild)//没有右子树,说明到达了终端
			{
				cout << t->data << " ";//打印终端
				sta.pop();
				p = t->rchild;
			}
			else {//是根节点
				if (tag[t] == 1)
				{
					tag[t] = 2;
					p=t->rchild;//尾递归，不用压入
				}
				else if(tag[t]==2)
				{
					cout << t->data << " ";
					sta.pop();//退栈，回到上一层
					p = NULL;
				}
			}
		}
	}
}
