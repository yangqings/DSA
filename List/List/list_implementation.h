#pragma once
#include "../../Vector/vector.h"

//保护函数
template <typename T> void List<T>::init() {//列表初始化
	header = new ListNode<T>;  //头节点
	trailer = new ListNode<T>; //尾节点
	header->succ = trailer; header -> = NULL;
	tralier->pred = header; trailer->succ = NULL;
	_size = 0;
}

//清空列表，返回被删除列表的大小
template <typename T>
int List<T>::clear(){
	int oldSize = _size;
	while (0 < _size)remove(header->succ);
	return oldSize;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init();
	//从p后的n项作为末节点插入
	while (n--) { insertAsLast(p->data); p = p->succ; }
}

//公有函数
template <typename T> 
List<T>::List(List<T> const& L) {
	copyNodes(L.first(), L._size);
}

//复制列表第r项起，到第n项，r+n<=L.size
template <typename T> 
List<T>::List(List<T> const& L, Rank r, int n) {
	copyNodes(L[r],n);
}

//复制列表P的n项，p为合法位置且至少有n-1个后继节点
template <typename T>
List<T>::List(ListNodePosi(T) p, int n) {
	copyNodes(p, n);
}

template <typename T>
List<T>::~List() {
	clear(); delete header; delete trailer;
}

//重载[]操作符，0<=r<size，秩访问节点，效率低
template <typename T>
T& List<T>::operator[](Rank r)const {
	ListNodePosi(T) p = first();
	while (0 < r--)p = p->succ;
	return p->data;
}

//删除节点，返回节点的数据
template <typename T>
T List<T>::remove(ListNodePosi(T) p){
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;

	return e;
}
