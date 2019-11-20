#pragma once
#include "../Vector/vector.h"
//构造的类为模板类，派生类不可以直接使用继承到的几类数据和方法，需要通过this指针使用

template <typename T> class Stack: public Vector<T>
{
public:
	void push(T const& e) { this->insert(this->size(), e); } //入栈，实际是往向量后增加一个元素
	T pop() { return this->remove(this->size() - 1); }//出栈,实际是删除向量最后一个元素
	T& top() { return (*this)[this->size() - 1]; }
};