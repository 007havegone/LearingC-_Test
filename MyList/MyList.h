#pragma once
typedef int Statu;
enum {ERROR,OK};
const int MAXSIZE = 100;//֧�ֵ����ռ�
class ArrayList
{
private:
	int limitsize;
	int listsize;
	int *elemts;
public:
	ArrayList(int size);//�����ռ�Ϊn
	ArrayList();//���캯��
	~ArrayList();//��������
	Statu Insert(int num, int i);
	Statu Delete(int &num, int i);
	Statu GetElemt(int & num,int i);
	Statu Clear();
	void Show();
	bool isEmpty();
	bool isFull();
	int getSize();
	
};
