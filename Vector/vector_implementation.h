#pragma once
#include "pch.h"
#include "vector.h"

//���������Ա���������ز������Ķ���
//���ڸ��Ƶ�����������
template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi)
		_elem[_size++] = A[lo++];//��һ���Ƶ�_elem[0,hi-lo)
}

//����"="������
template <typename T> 
Vector<T>& Vector<T>::operator= (Vector<T> const& V) {
	if (_elem) delete[] _elem;//�ͷ�ԭ������
	copyFrom(V._elem, 0, V.size());
	return *this;//���ص�ǰ��������ã��Ա���ʽ��ֵ
}

//����"[]"������
template <typename T> 
T& Vector<T>::operator[](Rank r)const
{
	return _elem[r];
}

//����
template <typename T> 
void Vector<T>::expand() { 
	if (_size < _capacity)return;
	if (_capacity < DEFAULT_CAPACITY)_capacity = DEFAULT_CAPACITY;
	T* oldElem = _elem; _elem = new T[_capacity <<= 1];//�����ӱ�
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];//����ԭ��������
	delete[] oldElem;//�ͷ�ԭ�ռ�

}

//����
template <typename T> 
void Vector<T>::shrink() { 
	if (_capacity < DEFAULT_CAPACITY)return;
	if (_size << 2 > _capacity)return;//��������25%����
	T* oldElem = _elem; _elem = new T[_capacity >>= 1];//��������(x>>=1�ȼ���x=x>>1)
	for (int i = 0; i < _size; i++)_elem[i] = oldElem[i];
	delete[] oldElem;
}

//ɨ�轻��
template <typename T> 
bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true;
	while (++lo < hi)//��������
		if (_elem[lo - 1] > _elem[lo]) {//���򣬽���
			sorted = false;
			std::swap(_elem[lo - 1], _elem[lo]);
		}
	return sorted;
}

//����
template <typename T> 
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	for (int i = _size; i > r; i--)_elem[i] = _elem[i - 1];//��rԪ�ؿ�ʼ����һ����Ԫ
	_elem[r] = e;
	_size++;
	return r;
}

//�����㷨
template <typename T> 
void Vector<T>::permute(void){
	printf("\n");
	printf("Execute Permute Function:\n");
	for (int i = _size; i > 0; i--)//�Ӻ���ǰ
		std::swap(_elem[i - 1], _elem[rand() % i]);//�������V[i-1]��V[0,i)Ԫ��
}

//ð������
template <typename T> 
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	printf("\n");
	printf("BubbleSort[%3d, %3d):\n", lo, hi);
	while (!bubble(lo, hi--));
}

//����ӿں�����sortMethodѡ�������㷨
template <typename T> 
void Vector<T>::sort(Rank lo, Rank hi, int sortMethod) {
	switch (sortMethod) {
	case 1:bubbleSort(lo, hi); break;
	case 2:break;
	default:break;
	}
}

//�����������ҽӿ�
//e��Ŀ��ֵ
template <typename T>
Rank Vector<T>::find(T const&e, Rank lo, Rank hi)const {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;//��hi<lo������ʧ��
}

//�����������ҽӿ�
//e��Ŀ��ֵ
template <typename T>
Rank Vector<T>::search(T const&e, Rank lo, Rank hi)const {

}

//����
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

