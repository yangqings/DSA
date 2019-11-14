#pragma once
#include "../Vector/vector.h"

//保护函数
template <typename T> void List<T>::init() {//列表初始化
	header = new ListNode<T>;  //头节点
	trailer = new ListNode<T>; //尾节点
	header->succ = trailer; header ->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;
}

//清空列表，返回被删除列表的大小
template <typename T>
int List<T>::clear(){
	int oldSize = _size;
	while (0 < _size)remove(header->succ);
	return oldSize;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init();
	//从p后的n项作为末节点插入
	while (n--) { insertAsLast(p->data); p = p->succ; }
}


//排序算法的实现
//插入排序,从首节点开始 search()操作所需时间在O(1)~O(n),排序平均复杂度O(n^2)
template <typename T>
void List<T>::insertionSort(ListNodePosi(T)p, int n) {
	std::cout << "InsertionSort:\n";
	for (int r = 1; r <= n; r++) {
		insertA(search(p->data, r,p),p->data);//从左到右遍历有序列表，找到合适位置插入
		p = p -> succ;  //指向下一个节点
		remove(p->pred);//删除已排序的节点
	}
	
}

//选择排序,从首节点选择最大元素，最大元素插入从末节点往前，选择区间逐渐减小
//selectMax必须遍历无序前缀，平均复杂度O(n^2) 借助更高级数据结构可优化至nlog(n)
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n) {
	std::cout << "SelectionSort:\n";
	ListNodePosi(T) head = p->pred;//保存首节点，用以 每次从首节点开始找最大元素
	ListNodePosi(T) trail = p;

	//p指向尾节点
	for (int i = 0; i < n; i++)trail = trail->succ;//用以 从末尾开始插入乱序节点的最大元素

	while (1<n) {
		ListNodePosi(T) max = selectMax(head->succ, n);
		insertB(trail ,remove(max));
		trail = trail->pred; n--;
	}
}

//公有函数
template <typename T> 
List<T>::List(List<T> const& L) {
	copyNodes(L.first(), L._size);
}

//复制列表第r项起，到第n项，r+n<=L.size
template <typename T> 
List<T>::List(List<T> const& L, Rank r, int n) {
	copyNodes(L[r],n);
}

//复制列表P的n项，p为合法位置且至少有n-1个后继节点
template <typename T>
List<T>::List(ListNodePosi(T) p, int n) {
	copyNodes(p, n);
}

template <typename T>
List<T>::~List() {
	clear(); delete header; delete trailer;
}

//无序区间查找
template <typename T>
ListNodePosi(T) List<T>::find(T const&e, int n, ListNodePosi(T) p) const{
	while (0 < n--)
		if (e == (p = p->pred)->data)return p;
	return NULL;
}

//有序区间的查找
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

//从左到右选择最大元素
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {
	ListNodePosi(T) max=p;
	while (n--) {
		if((p->data) > (max->data)) max = p ;
		p = p -> succ;
	}
	return max;
}

//将e作为首节点插入（头节点后一个节点）
template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e){
	_size++; return header->insertAsSucc(e); 
}

//将e作为末节点插入（尾节点前一个节点）
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

//排序
template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n) {
	//insertionSort(p, n);
	selectionSort(p,n);
}

//重载[]操作符，0<=r<size，秩访问节点，效率低
template <typename T>
T& List<T>::operator[](Rank r)const {
	ListNodePosi(T) p = first();
	while (0 < r--)p = p->succ;
	return p->data;
}

//删除节点，返回节点的数据
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
