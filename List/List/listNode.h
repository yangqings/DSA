#pragma once
typedef int Rank;
#define NULL 0

#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode {//�б�ڵ�ģ����(˫������)
	T data; ListNodePosi(T) pred; ListNodePosi(T) succ;

	//���캯��
	ListNode(){}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		:data(e), pred(p),succ(s) {}

};



