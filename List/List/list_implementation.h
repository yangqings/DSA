#pragma once
#include "../../Vector/vector.h"


template <typename T> void List<T>::init() {//列表初始化
	header = new ListNode<T>;  //头节点
	trailer = new ListNode<T>; //尾节点
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

