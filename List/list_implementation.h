#pragma once
#include "../Vector/vector.h"

//��������
template <typename T> void List<T>::init() {//�б��ʼ��
	header = new ListNode<T>;  //ͷ�ڵ�
	trailer = new ListNode<T>; //β�ڵ�
	header->succ = trailer; header ->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;
}

//����б����ر�ɾ���б�Ĵ�С
template <typename T>
int List<T>::clear(){
	int oldSize = _size;
	while (0 < _size)remove(header->succ);
	return oldSize;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init();
	//��p���n����Ϊĩ�ڵ����
	while (n--) { insertAsLast(p->data); p = p->succ; }
}


//�����㷨��ʵ��
//��������,���׽ڵ㿪ʼ search()��������ʱ����O(1)~O(n),����ƽ�����Ӷ�O(n^2)
template <typename T>
void List<T>::insertionSort(ListNodePosi(T)p, int n) {
	std::cout << "InsertionSort:\n";
	for (int r = 1; r <= n; r++) {
		insertA(search(p->data, r,p),p->data);//�����ұ��������б��ҵ�����λ�ò���
		p = p -> succ;  //ָ����һ���ڵ�
		remove(p->pred);//ɾ��������Ľڵ�
	}
	
}

//ѡ������,���׽ڵ�ѡ�����Ԫ�أ����Ԫ�ز����ĩ�ڵ���ǰ��ѡ�������𽥼�С
//selectMax�����������ǰ׺��ƽ�����Ӷ�O(n^2) �������߼����ݽṹ���Ż���nlog(n)
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n) {
	std::cout << "SelectionSort:\n";
	ListNodePosi(T) head = p->pred;//�����׽ڵ㣬���� ÿ�δ��׽ڵ㿪ʼ�����Ԫ��
	ListNodePosi(T) trail = p;

	//pָ��β�ڵ�
	for (int i = 0; i < n; i++)trail = trail->succ;//���� ��ĩβ��ʼ��������ڵ�����Ԫ��

	while (1<n) {
		ListNodePosi(T) max = selectMax(head->succ, n);
		insertB(trail ,remove(max));
		trail = trail->pred; n--;
	}
}

//���к���
template <typename T> 
List<T>::List(List<T> const& L) {
	copyNodes(L.first(), L._size);
}

//�����б��r���𣬵���n�r+n<=L.size
template <typename T> 
List<T>::List(List<T> const& L, Rank r, int n) {
	copyNodes(L[r],n);
}

//�����б�P��n�pΪ�Ϸ�λ����������n-1����̽ڵ�
template <typename T>
List<T>::List(ListNodePosi(T) p, int n) {
	copyNodes(p, n);
}

template <typename T>
List<T>::~List() {
	clear(); delete header; delete trailer;
}

//�����������
template <typename T>
ListNodePosi(T) List<T>::find(T const&e, int n, ListNodePosi(T) p) const{
	while (0 < n--)
		if (e == (p = p->pred)->data)return p;
	return NULL;
}

//��������Ĳ���
template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T)p)const {
	std::cout << "Search for: ";
	print(e);
	std::cout << "\n";
	while (0 < n--) {
		if (((p = p->pred)->data) <= e)break;
	}
	return p;
}

//������ѡ�����Ԫ��
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {
	ListNodePosi(T) max=p;
	while (n--) {
		if((p->data) > (max->data)) max = p ;
		p = p -> succ;
	}
	return max;
}

//��e��Ϊ�׽ڵ���루ͷ�ڵ��һ���ڵ㣩
template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e){
	_size++; return header->insertAsSucc(e); 
}

//��e��Ϊĩ�ڵ���루β�ڵ�ǰһ���ڵ㣩
template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e) {
	_size++; return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const& e) {
	_size++; return p->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const & e) {
	_size++; return p->insertAsPred(e);
}

//����
template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n) {
	//insertionSort(p, n);
	selectionSort(p,n);
}

//����[]��������0<=r<size���ȷ��ʽڵ㣬Ч�ʵ�
template <typename T>
T& List<T>::operator[](Rank r)const {
	ListNodePosi(T) p = first();
	while (0 < r--)p = p->succ;
	return p->data;
}

//ɾ���ڵ㣬���ؽڵ������
template <typename T>
T List<T>::remove(ListNodePosi(T) p){
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;

	return e;
}


template <typename T>
void List<T>::traverse(void(*visit)(T&)) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}

template <typename T> template <typename VST> void List<T>::traverse(VST& visit)
{
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)visit(p->data);
}
