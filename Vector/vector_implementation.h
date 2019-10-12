#pragma once
#include "pch.h"
#include "vector.h"

//以下是类成员函数和重载操作符的定义
//基于复制的向量构造器
template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi)
		_elem[_size++] = A[lo++];//逐一复制到_elem[0,hi-lo)
}

//重载"="操作符
template <typename T> 
Vector<T>& Vector<T>::operator= (Vector<T> const& V) {
	if (_elem) delete[] _elem;//释放原有内容
	copyFrom(V._elem, 0, V.size());
	return *this;//返回当前对象的引用，以便链式赋值
}

//重载"[]"操作符
template <typename T> 
T& Vector<T>::operator[](Rank r)const
{
	return _elem[r];
}

//扩容
template <typename T> 
void Vector<T>::expand() { 
	if (_size < _capacity)return;
	if (_capacity < DEFAULT_CAPACITY)_capacity = DEFAULT_CAPACITY;
	T* oldElem = _elem; _elem = new T[_capacity <<= 1];//容量加倍
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];//复制原向量内容
	delete[] oldElem;//释放原空间

}

//缩容
template <typename T> 
void Vector<T>::shrink() { 
	if (_capacity < DEFAULT_CAPACITY)return;
	if (_size << 2 > _capacity)return;//不收缩到25%以下
	T* oldElem = _elem; _elem = new T[_capacity >>= 1];//容量减半(x>>=1等价于x=x>>1)
	for (int i = 0; i < _size; i++)_elem[i] = oldElem[i];
	delete[] oldElem;
}

//扫描交换
template <typename T> 
bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true;
	while (++lo < hi)//自左向右
		if (_elem[lo - 1] > _elem[lo]) {//逆序，交换
			sorted = false;
			std::swap(_elem[lo - 1], _elem[lo]);
		}
	return sorted;
}

//插入
template <typename T> 
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	for (int i = _size; i > r; i--)_elem[i] = _elem[i - 1];//从r元素开始后移一个单元
	_elem[r] = e;
	_size++;
	return r;
}

//置乱算法
template <typename T> 
void Vector<T>::permute(void){
	printf("\n");
	printf("Execute Permute Function:\n");
	for (int i = _size; i > 0; i--)//从后向前
		std::swap(_elem[i - 1], _elem[rand() % i]);//随机交换V[i-1]与V[0,i)元素
}

//冒泡排序
template <typename T> 
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	printf("\n");
	printf("BubbleSort[%3d, %3d):\n", lo, hi);
	while (!bubble(lo, hi--));
}

//排序接口函数，sortMethod选择排序算法
template <typename T> 
void Vector<T>::sort(Rank lo, Rank hi, int sortMethod) {
	switch (sortMethod) {
	case 1:bubbleSort(lo, hi); break;
	case 2:break;
	default:break;
	}
}

//无序向量查找接口
//e是目标值
template <typename T>
Rank Vector<T>::find(T const&e, Rank lo, Rank hi)const {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;//若hi<lo，查找失败
}

//有序向量查找接口
//e是目标值
template <typename T>
Rank Vector<T>::search(T const&e, Rank lo, Rank hi)const {

}

//遍历
template <typename T> 
void Vector<T>::traverse(void(*visit) (T&)) {
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}

//
template <typename T> template <typename VST>
void Vector<T>::traverse(VST& visit) {
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}

