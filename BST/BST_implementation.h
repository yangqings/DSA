
#pragma once
#include "BST.h"
#include "BST_searchIn.h"
#include "BST_removeAt.h"
template <typename T> BinNodePosi(T) BST <T>::connect34(
	BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c, 
	BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3) 
{
	a->lc = T0; if (T0) T0->parent = a;
	a->rc = T1; if (T1) T1->parent = a;
	updateHeight(a);
	c->lc = T2; if (T2) T2->parent = c;
	c->rc = T3; if (T3) T3->parent = c;
	updateHeight(c);
	b->lc = a; a->parent = b;
	b->rc = c; c->parent = b;
	updateHeight(b);
	return b;
}


template <typename T>//BST�ڵ���ת��������ת��ֲ��������ڵ��λ��
BinNodePosi(T) BST<T>::rotateAt(BinNodePosi(T) v)
{
	if (!v) {
		printf("\nFail to rotate NULL node!\n");
		exit(-1);
	}
	BinNodePosi(T) p = v->parent;
	BinNodePosi(T) g = p->parent;
	/*����v��p��g���λ�÷�Ϊ�������*/
	if (IsLChild(*p))/*zig��ת*/

	else /*zag��ת*/

}

template <typename T>
BinNodePosi(T) & BST<T>::search(const T& e)
{
	return searchIn(_root, e, _hot = NULL);
}

template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e)
{
	BinNodePosi(T) & x = search(e);
	if (x)return x;//x��Ч������x
	x = new BinNode<T>(e, _hot);//�����½ڵ�x,��_hot���ڵ����
	_size++;
	updateHeightAbove(x);
	return x;
}

template <typename T>
bool BST<T>::remove(const T& e)
{
	BinNodePosi(T) & x = search(e);
	if (!x)return false;//����NULL��ȷ��x�����ڣ�û��e
	removeAt(x, _hot);//���ز�ΪNULL��x���ڣ�ɾ���ڵ�
	_size--;
	updateHeightAbove(_hot);
	return true;
}

