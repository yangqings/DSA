#pragma once
#include "../List/list.h"

//队列模板类，以List为基类
template <typename T> class Queue :public List<T> {
public:
	void enqueue(T const& e) { this->insertAsLast(e); }//入队列
	T dequeue() { return this->remove(this->first()); }//出队列
	T& front() { return (this->first())->data; }    //队首元素
};