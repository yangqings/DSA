#pragma once
#include "../Vector/vector.h"

template <typename T> class Stack: public Vector<T>
{
public:
	void push(T const& e) { insert(size(), e); } //��ջ��ʵ����������������һ��Ԫ��
	T pop() { return remove(size() - 1); }//��ջ,ʵ����ɾ���������һ��Ԫ��
	T& top() { return (*this)[size() - 1]; }
};