#pragma once
typedef int Rank;
#define NULL 0

#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode {//列表节点模板类(双向链表)
	T data; ListNodePosi(T) pred; ListNodePosi(T) succ;//数值、前驱节点、后继节点

	//构造函数
	ListNode(){}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		:data(e), pred(p),succ(s) {}

	//接口
	ListNodePosi(T) insertAsPred(T const& e);//节点前插入新节点
	ListNodePosi(T) insertAsSucc(T const& e);//节点后插入新节点

};

//非静态成员函数内部，this表示指向该函数所作用的对象的指针
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this);//新节点的后继是当前节点,this是当前节点

	//以下这两步的顺序不能反
	pred-> succ = x;//节点的前驱节点的后继指向新节点
	pred = x;//节点的前驱指向新节点

	return x;//返回新节点的位置
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi(T) x = new ListNode(e, this, succ);//新节点的前驱是当前节点,this是当前节点

	succ-> pred = x;//节点的后继节点的前驱指向新节点
	succ = x;//节点的后继指向新节点

	return x;
}



