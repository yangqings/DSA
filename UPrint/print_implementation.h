#pragma once
#include "../UPrint/pch.h"

#define ROOT 0
#define L_CHILD 1
#define R_CHILD -1*L_CHILD

void UniPrint::p(int e) { printf("%4d ", e); }
void UniPrint::p(float e) { printf("%4.1f ", e); }
void UniPrint::p(double e) { printf("%4.1f ", e); }
void UniPrint::p(char e) { printf("%4c ", ((31 < e) && (e < 128))? e : '$'); }

//typeid():����ָ���������ָ�����ʵ������
template <typename T>
void UniPrint::p(T& s) {
	printf("%s[%p]*%d:\n", typeid(s).name(), &s, s.size());
	s.traverse( print );
	printf("\n");
}
//%p���ָ���ֵַ

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
 * �����������������ͳһ��ӡ
 ******************************************************************************************/
template <typename T> //Ԫ������
static void printBinTree(BinNodePosi(T) bt, int depth, int type, Bitmap* bType) {
    if (!bt) return;
    if (-1 < depth) //���õ�ǰ��Ĺ����־
        R_CHILD == type ? bType->set(depth) : bType->clear(depth);
    printBinTree(bt->rc, depth + 1, R_CHILD, bType); //�����������ϣ�
    print(bt); printf("*");
    for (int i = -1; i < depth; i++) //�������ڸ���
        if ((0 > i) || bType->test(i) == bType->test(i + 1)) //�Ĺ����Ƿ�һ�£�����ȷ��
              printf("    "); //�Ƿ�Ӧ��
        else  printf(" ��  "); //��ӡ����
    switch (type) {
    case  R_CHILD:  printf(" ���� ");  break;
    case  L_CHILD:  printf(" ���� ");  break;
    default:  printf("����");  break; //root
    }
    print(bt);
#if defined(DSA_HUFFMAN)
    if (IsLeaf(*bt)) bType->print(depth + 1); //���Huffman����
#endif
    printf("\n");
    printBinTree(bt->lc, depth + 1, L_CHILD, bType); //�����������£�
}

template <typename T> 
void UniPrint::p(BinTree<T>& tree)
{
	printf("\n%s[%p]*%d:\n", typeid (tree).name(), &tree, tree.size()); //������Ϣ����������ַ����С
    Bitmap* branchType = new Bitmap;
    printBinTree(tree.root(), -1, ROOT, branchType);
    release(branchType);
    printf("\n");
}

