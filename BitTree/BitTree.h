#ifndef BITTREE_T_
#define BITTREE_T_

enum LOC { LEFT,RIGHT };
typedef int TElemType;
#define MAXDEAPTH 50//������50
#define OK 1
#define ERROR 0
typedef struct BitNode
{
	TElemType data;
	BitNode *lchild, *rchild;
	//�����������������������2��ʡ�Բ�д
	int LTag;//���ұ�־��1��������0�к���
	int RTag;
}BitNode,*BitTree;
void CreateBitTree(BitTree &T);//����������������
bool BitTreeEmpty(BitTree t);//�������Ƿ�Ϊ����
void CopyTree(BitTree t1, BitTree &t2);//������
void DestoryTree(BitTree &t);//������
int TreeDepth(BitTree t);//�������
int NodeCount(BitTree t);//���Ľ����
void EchangeLRchile(BitTree &t);//������������
bool equal(BitTree t1, BitTree t2);//�Ƚ���t1�Ƿ����t2
BitNode* getLoca(BitTree t, TElemType e);//��ȡ���ֵΪe��λ��
bool AddNode(BitTree &t,TElemType par,TElemType e,LOC loc);//��ӽ����Ŀ�������������������ý���������Һ��ӣ����ʧ��
void LessThan(BitTree t, TElemType e);//��ӡ��eС��Ԫ��
void GreatThan(BitTree t, TElemType e);//��ӡ��e���Ԫ��
int LeavesCount(BitTree t);//����Ҷ�ӽ�����
int getMaxWidth(BitTree t);//��ȡ���������в��н����������ֵ
int getTD1Count(BitTree t);//��α�����ȡ��Ϊ1�Ľ��
void ShowDepthestPath(BitTree t);//�ҵ���һ�����·��
void GetPath(BitTree t,TElemType path[],int pathlen);//���ÿ��Ҷ�ڵ㵽���ڵ��·��
//����
void PreOrderTraverse(BitTree T);//�������
void InOrderTraverse(BitTree T);//�������
void PostOrderTraverse(BitTree T);//�������
void RePreOrderTraverse(BitTree T);
void ReInOrderTraverse(BitTree T);
void RePostOrderTraverse(BitTree T);

//��������ֻ������������
void InOrderTraverse_Thr(BitTree head);//headָ��ͷ���
void InThreading(BitTree t,BitTree &pre);//��������������,preΪͷ���
void InOrderThreading(BitTree t, BitTree &head);//��ͷ���Ķ���������������
#endif // !BITRTEE_T_

