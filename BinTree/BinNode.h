#pragma once
#include <stddef.h>
#define BinNodePosi(T)  BinNode<T>*
typedef enum { RB_RED=0, RB_BLACK }RBColor;
#define stature(p) ((p)?(p)->height:-1)//Լ�������߶�Ϊ-1

//�ṹ����������𣺽ṹ��Ĭ�����ݳ�Ա�ͺ�����Ա�ķ��ʿ�������Ϊ��������
//�������ڵ�ģ��
template <typename T> struct BinNode {
	T data;
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
	int height;
	int npl;
	RBColor color;

	//���캯��
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED){ }
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) :
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c){ }

	//�ӿ�
	int size();
	BinNodePosi(T) insertAsLC(T const& e);
	BinNodePosi(T) insertAsRC(T const& e);
	BinNodePosi(T) succ();

	template <typename VST> void travLevel(const VST&);//��α���
	template <typename VST> void travIn(const VST&);//�������

};

#include "BinNode_implementation.h"