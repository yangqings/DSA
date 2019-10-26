#pragma once
#include "../../Vector/vector.h"

//��������
template <typename T> void List<T>::init() {//�б��ʼ��
	header = new ListNode<T>;  //ͷ�ڵ�
	trailer = new ListNode<T>; //β�ڵ�
	header->succ = trailer; header -> = NULL;
	tralier->pred = header; trailer->succ = NULL;
	_size = 0;
}

//����б����ر�ɾ���б�Ĵ�С
template <typename T>
int List<T>::clear(){
	int oldSize = _size;
	while (0 < _size)remove(header->succ);
	return oldSize;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init();
	//��p���n����Ϊĩ�ڵ����
	while (n--) { insertAsLast(p->data); p = p->succ; }
}

//���к���
template <typename T> 
List<T>::List(List<T> const& L) {
	copyNodes(L.first(), L._size);
}

//�����б��r���𣬵���n�r+n<=L.size
template <typename T> 
List<T>::List(List<T> const& L, Rank r, int n) {
	copyNodes(L[r],n);
}

//�����б�P��n�pΪ�Ϸ�λ����������n-1����̽ڵ�
template <typename T>
List<T>::List(ListNodePosi(T) p, int n) {
	copyNodes(p, n);
}

template <typename T>
List<T>::~List() {
	clear(); delete header; delete trailer;
}

//����[]��������0<=r<size���ȷ��ʽڵ㣬Ч�ʵ�
template <typename T>
T& List<T>::operator[](Rank r)const {
	ListNodePosi(T) p = first();
	while (0 < r--)p = p->succ;
	return p->data;
}

//ɾ���ڵ㣬���ؽڵ������
template <typename T>
T List<T>::remove(ListNodePosi(T) p){
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;

	return e;
}
