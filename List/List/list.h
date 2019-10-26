#pragma once
#include "listNode.h"

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

	//�ӿں���
	ListNodePosi(T)first()const { return header->succ; }
	ListNodePosi(T)last()const { return trailer->pred; }
	T& operator[] (Rank r)const;//����[]������
	T remove(ListNodePosi(T) p);//ɾ���ڵ㣬���ر�ɾ���Ľڵ�
};



#include "list_implementation.h"