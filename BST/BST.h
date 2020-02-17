#pragma once
//����BST.cppʹ�õ�ͷ�ļ��ڴ˴�����
#include <iostream>
#include "../BinTree/BinTree.h"

using namespace std;

template <typename T> class BST : public BinTree<T> {//������������ģ�壬�ɶ���������
protected:
	BinNodePosi(T) _hot;//����ʱ���нڵ�ĸ��ڵ�
	BinNodePosi(T) connect34(
		BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
		BinNodePosi(T)T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3); 
	BinNodePosi(T) rotateAt(BinNodePosi(T) x);//��x�ڵ�ĸ��ڵ��游�ڵ�ͳһ��ת
public:
	virtual BinNodePosi(T) & search(const T& e);//����
	virtual BinNodePosi(T)insert(const T& e);//����
	virtual bool remove(const T& e);//ɾ��
};

#include "BST_implementation.h"