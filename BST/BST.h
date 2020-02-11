#pragma once
#include <iostream>
#include "../BinTree/BinTree.h"

using namespace std;

template <typename T> class BST : public BinTree<T> {//������������ģ�壬�ɶ���������
protected:
	BinNodePosi(T) _hot;
	BinNodePosi(T) connect34();
public:
	virtual BinNodePosi(T) &search(const T& e);
	virtual BinNodePosi(T)insert(const T& e);
	virtual bool remove(const T& e);
};

#include "BST_implementation.h"