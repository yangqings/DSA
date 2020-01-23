#pragma once
#include "../UPrint/pch.h"

#define ROOT 0
#define L_CHILD 1
#define R_CHILD -1*L_CHILD

void UniPrint::p(int e) { printf("%4d ", e); }
void UniPrint::p(float e) { printf("%4.1f ", e); }
void UniPrint::p(double e) { printf("%4.1f ", e); }
void UniPrint::p(char e) { printf("%4c ", ((31 < e) && (e < 128))? e : '$'); }

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

/******************************************************************************************
 * 二叉树各种派生类的统一打印
 ******************************************************************************************/
template <typename T> //元素类型
static void printBinTree(BinNodePosi(T) bt, int depth, int type, Bitmap* bType) {
    if (!bt) return;
    if (-1 < depth) //设置当前层的拐向标志
        R_CHILD == type ? bType->set(depth) : bType->clear(depth);
    printBinTree(bt->rc, depth + 1, R_CHILD, bType); //右子树（在上）
    print(bt); printf("*");
    for (int i = -1; i < depth; i++) //根据相邻各层
        if ((0 > i) || bType->test(i) == bType->test(i + 1)) //的拐向是否一致，即可确定
              printf("    "); //是否应该
        else  printf(" │  "); //打印横线
    switch (type) {
    case  R_CHILD:  printf(" ┌─ ");  break;
    case  L_CHILD:  printf(" └─ ");  break;
    default:  printf("──");  break; //root
    }
    print(bt);
#if defined(DSA_HUFFMAN)
    if (IsLeaf(*bt)) bType->print(depth + 1); //输出Huffman编码
#endif
    printf("\n");
    printBinTree(bt->lc, depth + 1, L_CHILD, bType); //左子树（在下）
}

template <typename T> 
void UniPrint::p(BinTree<T>& tree)
{
	printf("\n%s[%p]*%d:\n", typeid (tree).name(), &tree, tree.size()); //基本信息：类名、地址、大小
    Bitmap* branchType = new Bitmap;
    printBinTree(tree.root(), -1, ROOT, branchType);
    release(branchType);
    printf("\n");
}

