#ifndef BITTREE_T_
#define BITTREE_T_

enum LOC { LEFT,RIGHT };
typedef int TElemType;
#define MAXDEAPTH 50//最大深度50
#define OK 1
#define ERROR 0
typedef struct BitNode
{
	TElemType data;
	BitNode *lchild, *rchild;
	//如果不进行线索操作，下面2行省略不写
	int LTag;//左右标志，1有线索，0有孩子
	int RTag;
}BitNode,*BitTree;
void CreateBitTree(BitTree &T);//先序遍历构造二叉树
bool BitTreeEmpty(BitTree t);//二叉树是否为空树
void CopyTree(BitTree t1, BitTree &t2);//复制树
void DestoryTree(BitTree &t);//销毁树
int TreeDepth(BitTree t);//树的深度
int NodeCount(BitTree t);//树的结点数
void EchangeLRchile(BitTree &t);//交换左右子树
bool equal(BitTree t1, BitTree t2);//比较树t1是否等于t2
BitNode* getLoca(BitTree t, TElemType e);//获取结点值为e的位置
bool AddNode(BitTree &t,TElemType par,TElemType e,LOC loc);//添加结点在目标结点的左右子树，如果该结点已有左右孩子，添加失败
void LessThan(BitTree t, TElemType e);//打印比e小的元素
void GreatThan(BitTree t, TElemType e);//打印比e大的元素
int LeavesCount(BitTree t);//返回叶子结点个数
int getMaxWidth(BitTree t);//获取二叉树所有层中结点个数的最大值
int getTD1Count(BitTree t);//层次遍历获取度为1的结点
void ShowDepthestPath(BitTree t);//找到第一个最长的路径
void GetPath(BitTree t,TElemType path[],int pathlen);//输出每个叶节点到根节点的路径
//遍历
void PreOrderTraverse(BitTree T);//先序遍历
void InOrderTraverse(BitTree T);//中序遍历
void PostOrderTraverse(BitTree T);//后序遍历
void RePreOrderTraverse(BitTree T);
void ReInOrderTraverse(BitTree T);
void RePostOrderTraverse(BitTree T);

//线索化后只能用线索访问
void InOrderTraverse_Thr(BitTree head);//head指向头结点
void InThreading(BitTree t,BitTree &pre);//中序线索化该树,pre为头结点
void InOrderThreading(BitTree t, BitTree &head);//带头结点的二叉树中序线索化
#endif // !BITRTEE_T_

