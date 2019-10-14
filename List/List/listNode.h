#pragma once
typedef int Rank;
#define NULL 0

#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode {//列表节点模板类(双向链表)
	T data; ListNodePosi(T) pred; ListNodePosi(T) succ;

	//构造函数
	ListNode(){}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		:data(e), pred(p),succ(s) {}

};



