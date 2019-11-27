#pragma once
#include "../List/list.h"

//����ģ���࣬��ListΪ����
template <typename T> class Queue :public List<T> {
public:
	void enqueue(T const& e) { this->insertAsLast(e); }//�����
	T dequeue() { return this->remove(this->first()); }//������
	T& front() { return (this->first())->data; }    //����Ԫ��
};