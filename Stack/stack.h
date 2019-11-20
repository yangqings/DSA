#pragma once
#include "../Vector/vector.h"
//�������Ϊģ���࣬�����಻����ֱ��ʹ�ü̳е��ļ������ݺͷ�������Ҫͨ��thisָ��ʹ��

template <typename T> class Stack: public Vector<T>
{
public:
	void push(T const& e) { this->insert(this->size(), e); } //��ջ��ʵ����������������һ��Ԫ��
	T pop() { return this->remove(this->size() - 1); }//��ջ,ʵ����ɾ���������һ��Ԫ��
	T& top() { return (*this)[this->size() - 1]; }
};