#pragma once
#include "listNode.h"
#include "../UPrint/print.h"

template <typename T> class List {//�б���ģ��

private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;

protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T) p, int n);

public:
	//���캯��
	List() { init(); }                    //Ĭ�ϳ�ʼ��
	List(List<T> const& L);               //���帴���б�
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	//��������
	~List();
	Rank size() const { return _size; } //��ģ
	//�ӿں���
	ListNodePosi(T)first()const { return header->succ; }
	ListNodePosi(T)last()const { return trailer->pred; }

	ListNodePosi(T)insertAsFirst(T const& e);
	ListNodePosi(T)insertAsLast(T const& e);
	ListNodePosi(T)insertA(ListNodePosi(T) p, T const& e);
	ListNodePosi(T)insertB(ListNodePosi(T) p, T const& e);

	T& operator[] (Rank r)const;//����[]������
	T remove(ListNodePosi(T) p);//ɾ���ڵ㣬���ر�ɾ���Ľڵ�

	void traverse(void(*visit)(T&));//����
    template <typename VST>
	void traverse(VST&);
};

#include "list_implementation.h"