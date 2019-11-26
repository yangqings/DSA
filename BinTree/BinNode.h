#pragma once
#include <stddef.h>
#define BinNodePosi(T)  BinNode<T>*
typedef enum { RB_RED, RB_BLACK }RBColor;

//结构体与类的区别：结构体默认数据成员和函数成员的访问控制属性为公有类型
//二叉树节点模板
template <typename T> struct BinNode {
	T data;
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
	int height;
	int npl;
	RBColor color;

	//构造函数
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED){ }
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) :
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c){ }

	//接口
	int size();
	BinNodePosi(T) insertAsLC(T const& e);
	BinNodePosi(T) insertAsRC(T const& e);


};
