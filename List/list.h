#pragma once
#include "listNode.h"
#include "../UPrint/print.h"

template <typename T> class List {//列表类模板

private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;

protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T) p, int n);
	void insertionSort(ListNodePosi(T) p, int n);
	void selectionSort(ListNodePosi(T) p, int n);
	void merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m);//有序列表并归
	void mergeSort(ListNodePosi(T)& p,int n);//并归排序

public:
	//构造函数
	List() { init(); }                    //默认初始化
	List(List<T> const& L);               //整体复制列表
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	//析构函数
	~List();
	Rank size() const { return _size; } //规模
	bool empty()const { return _size <= 0; }
	//接口函数
	ListNodePosi(T)first()const { return header->succ; }
	ListNodePosi(T)last()const { return trailer->pred; }

	ListNodePosi(T) find(T const& e)const //无序列表查找
	{
		return find(e, _size, trailer);//从后往前查找
	}
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p)const;//无序列表区间查找
	ListNodePosi(T) search(T const&e)//有序列表查找
	{
		return search(e, _size,trailer); //从后往前查找
	}
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p)const;//有序列表区间查找
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); }
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
	ListNodePosi(T)insertAsFirst(T const& e);
	ListNodePosi(T)insertAsLast(T const& e);
	ListNodePosi(T)insertA(ListNodePosi(T) p, T const& e);
	ListNodePosi(T)insertB(ListNodePosi(T) p, T const& e);

	//列表排序
	void sort(ListNodePosi(T) p, int n, int sortMethod);//区间排序

	T& operator[] (Rank r)const;//重载[]操作符
	T remove(ListNodePosi(T) p);//删除节点，返回被删除的节点

	void traverse(void(*visit)(T&));//遍历
    template <typename VST>
	void traverse(VST&);
};

#include "list_implementation.h"