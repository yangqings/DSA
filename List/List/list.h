#pragma once
#include "listNode.h"

template <typename T> class List {//�б���ģ��

private:
	int _size; ListNode(T) header; ListNode<T> trailer;

protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T), int);

public:
	//���캯��
	List() { init(); }                    //Ĭ�ϳ�ʼ��
	List(List<T> const& L);               //���帴���б�
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	//��������
	~List();

	//

};



#include "list_implementation.h"