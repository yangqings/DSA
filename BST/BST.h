#pragma once
//所有BST.cpp使用的头文件在此处声明
#include <iostream>
#include "../BinTree/BinTree.h"

using namespace std;

template <typename T> class BST : public BinTree<T> {//二叉搜索树类模板，由二叉树派生
protected:
	BinNodePosi(T) _hot;//查找时命中节点的父节点
	BinNodePosi(T) connect34(
		BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
		BinNodePosi(T)T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3); 
	BinNodePosi(T) rotateAt(BinNodePosi(T) x);//对x节点的父节点祖父节点统一旋转
public:
	virtual BinNodePosi(T) & search(const T& e);//查找
	virtual BinNodePosi(T)insert(const T& e);//插入
	virtual bool remove(const T& e);//删除
};

#include "BST_implementation.h"