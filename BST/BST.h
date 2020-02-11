#pragma once
#include <iostream>
#include "../BinTree/BinTree.h"

using namespace std;

template <typename T> class BST : public BinTree<T> {//二叉搜索树类模板，由二叉树派生
protected:
	BinNodePosi(T) _hot;
	BinNodePosi(T) connect34();
public:
	virtual BinNodePosi(T) &search(const T& e);
	virtual BinNodePosi(T)insert(const T& e);
	virtual bool remove(const T& e);
};

#include "BST_implementation.h"