#pragma once
#include "listNode.h"

template <typename T> class List {//列表类模板

private:
	int _size; ListNode(T) header; ListNode<T> trailer;

protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T), int);

public:
	//构造函数
	List() { init(); }                    //默认初始化
	List(List<T> const& L);               //整体复制列表
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	//析构函数
	~List();

	//

};



#include "list_implementation.h"