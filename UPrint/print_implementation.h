#pragma once
#include "../UPrint/pch.h"

void UniPrint::p(int e) { printf("%d ", e); }
void UniPrint::p(float e) { printf("%4.1f ", e); }
void UniPrint::p(double e) { printf("%4.1f ", e); }
void UniPrint::p(char e) { printf("%c ", ((31 < e) && (e < 128))? e : '$'); }


//typeid():返回指针或引用所指对象的实际类型
template <typename T>
void UniPrint::p(T& s) {
	printf("%s[%p]*%d:\n", typeid(s).name(), &s, s.size());
	s.traverse( print );
	printf("\n");
}
//%p输出指针地址值

template <typename T> void UniPrint::p(BinNode<T>& node)
{
	p(node.data);

	printf(
		((node.lc && &node != node.lc->parent) ||
		(node.rc && &node != node.rc->parent)) ?
		"@" : " "
	);
}

template <typename T> void UniPrint::p(BinTree<T>& tree)
{
	printf("%s[%d]*%d:\n", typeid (bt).name(), &bt, bt.size()); //基本信息
	//Bitmap* branchType = new Bitmap; //记录当前节点祖先的方向
	//printBinTree(bt.root(), -1, ROOT, branchType); //树状结构
	//release(branchType); printf("\n");
}