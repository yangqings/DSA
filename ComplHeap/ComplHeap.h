#pragma once
#include "../Vector/vector.h"
#include "../PQ/PQ.h"

template <typename T> class PQ_ComplHeap :public PQ<T>, public Vector <T> {
	friend class UniPrint;
protected:
	Rank percolateDown(Rank n,Rank i);//ÏÂÂË
	Rank percolateUp(Rank i);//ÉÏÂË
	void heapify(Rank n);//Floyd½¨¶Ñ
public:
	PQ_ComplHeap() {}
	PQ_ComplHeap(T* A, Rank n) { copyFrom(A, 0, n); heapify(n); }
	void insert(T);
	T getMax();
	T delMax();
};

#include "PQ_ComplHeap_implementation.h"