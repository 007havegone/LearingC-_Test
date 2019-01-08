#include "SqTree.h"
#include <iostream>
#include <algorithm>
using namespace std;
SqTree::SqTree(int size,ElemType root)
{
	m_iSize = size;
	m_pTree = new ElemType(size);
	for (int i = 0; i < size; i++)
	{
		m_pTree[i] = 0;
	}
	m_pTree[0] = root;
}

SqTree::~SqTree()
{
	delete[] m_pTree;
	m_pTree = NULL;
}

ElemType SqTree::SearchNode(int nodeIndex)
{
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return NULL;
	}
	if (m_pTree[nodeIndex] == 0)
	{
		return NULL;
	}
	return m_pTree[nodeIndex];
}

bool SqTree::AddNode(int nodeIndex, int direction,const ElemType & node)//0×ó1ÓÒ
{
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
		return false;
	if (m_pTree[nodeIndex] == 0)
		return false;
	if (direction == 0)
	{
		if (nodeIndex * 2 + 1 >= m_iSize)
		{
			return false;
		}
		if (m_pTree[nodeIndex * 2 + 1] != 0)
		{
			return false;
		}
		m_pTree[nodeIndex * 2 + 1]=node;
	}
	else
	{
		if (nodeIndex * 2 + 2 >= m_iSize)
		{
			return false;
		}
		if (m_pTree[nodeIndex * 2 + 2] != 0)
		{
			return false;
		}
		m_pTree[nodeIndex * 2 + 2] = node;
	}
	return true;
}

bool SqTree::DeleteNode(int nodeIndex, ElemType & node)
{
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
		return false;
	if (m_pTree[nodeIndex] == 0)
		return false;
	node = m_pTree[nodeIndex];
	m_pTree[nodeIndex] = 0;
	return true;
}

void SqTree::TreeTravese()
{
	for (int i = 0; i < m_iSize; i++)
		cout << m_pTree[i] << " ";
}

