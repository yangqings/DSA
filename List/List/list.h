#pragma once
#include "listNode.h"

template <typename T> class List {//列表类模板

private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;

protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T) p, int n);

public:
	//构造函数
	List() { init(); }                    //默认初始化
	List(List<T> const& L);               //整体复制列表
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	//析构函数
	~List();

	//接口函数
	ListNodePosi(T)first()const { return header->succ; }
	ListNodePosi(T)last()const { return trailer->pred; }
	T& operator[] (Rank r)const;//重载[]操作符
	T remove(ListNodePosi(T) p);//删除节点，返回被删除的节点
};



#include "list_implementation.h"