#pragma once
#include "../../Vector/vector.h"


template <typename T> void List<T>::init() {//�б��ʼ��
	header = new ListNode<T>;  //ͷ�ڵ�
	trailer = new ListNode<T>; //β�ڵ�
	header->succ = trailer; header -> = NULL;
	tralier->pred = header; trailer->succ = NULL;
	_size = 0;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init();
	while(n--){insertAsLast() }
}


template <typename T> List<T>::List(List<T> const& L) {
	copyNodes(L.first(), L._size);
}

