#ifndef SQTREE_H_
#define SQTREE_H_
typedef int ElemType;
class SqTree
{
public:
	SqTree(int size,ElemType root);
	~SqTree();
	ElemType SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex, int direction,const ElemType &node);
	bool DeleteNode(int nodeIndex, ElemType &node);
	void TreeTravese();
private:
		ElemType *m_pTree;
		int m_iSize;
};
#endif // !SQTREE_T_

