#pragma once

template<typename T> void PQ_ComplHeap<T>::heapify(Rank n) {

}

template <typename T> void PQ_ComplHeap<T>::insert(T e) {
	Vector<T>::insert(e);
	percolateUp(size - 1);
}

template <typename T> Rank PQ_ComplHeap<T>::percolateUp(Rank i) { /* 上滤 */

}

template <typename T> T PQ_ComplHeap<T>::delMax() {
	T maxElem = _elem[0];
	_elem[0] = _elem[--size];/* 删除堆顶，用末元素替代 */
	percolateDown(_size, 0);
	return maxElem;
}

template <typename T> Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i) {/* 下滤 */
	Rank j;
	while (i != (j = ProperParent(_elem, n, i)) {
		swap();
	}

	return i;
}