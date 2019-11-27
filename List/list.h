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
	void insertionSort(ListNodePosi(T) p, int n);
	void selectionSort(ListNodePosi(T) p, int n);
	void merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m);//�����б���
	void mergeSort(ListNodePosi(T)& p,int n);//��������

public:
	//���캯��
	List() { init(); }                    //Ĭ�ϳ�ʼ��
	List(List<T> const& L);               //���帴���б�
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	//��������
	~List();
	Rank size() const { return _size; } //��ģ
	bool empty()const { return _size <= 0; }
	//�ӿں���
	ListNodePosi(T)first()const { return header->succ; }
	ListNodePosi(T)last()const { return trailer->pred; }

	ListNodePosi(T) find(T const& e)const //�����б����
	{
		return find(e, _size, trailer);//�Ӻ���ǰ����
	}
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p)const;//�����б��������
	ListNodePosi(T) search(T const&e)//�����б����
	{
		return search(e, _size,trailer); //�Ӻ���ǰ����
	}
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p)const;//�����б��������
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); }
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
	ListNodePosi(T)insertAsFirst(T const& e);
	ListNodePosi(T)insertAsLast(T const& e);
	ListNodePosi(T)insertA(ListNodePosi(T) p, T const& e);
	ListNodePosi(T)insertB(ListNodePosi(T) p, T const& e);

	//�б�����
	void sort(ListNodePosi(T) p, int n, int sortMethod);//��������

	T& operator[] (Rank r)const;//����[]������
	T remove(ListNodePosi(T) p);//ɾ���ڵ㣬���ر�ɾ���Ľڵ�

	void traverse(void(*visit)(T&));//����
    template <typename VST>
	void traverse(VST&);
};

#include "list_implementation.h"