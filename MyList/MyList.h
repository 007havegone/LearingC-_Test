#pragma once
typedef int Statu;
enum {ERROR,OK};
const int MAXSIZE = 100;//支持的最大空间
class ArrayList
{
private:
	int limitsize;
	int listsize;
	int *elemts;
public:
	ArrayList(int size);//创建空间为n
	ArrayList();//构造函数
	~ArrayList();//析构函数
	Statu Insert(int num, int i);
	Statu Delete(int &num, int i);
	Statu GetElemt(int & num,int i);
	Statu Clear();
	void Show();
	bool isEmpty();
	bool isFull();
	int getSize();
	
};
