#pragma once
#include "../Vector/vector.h"

template <typename T> class Stack: public Vector<T>
{
public:
	void push(T const& e) { insert(size(), e); } //入栈，实际是往向量后增加一个元素
	T pop() { return remove(size() - 1); }//出栈,实际是删除向量最后一个元素
	T& top() { return (*this)[size() - 1]; }
};