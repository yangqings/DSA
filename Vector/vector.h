#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY  3 //Ĭ������
//�������� 0<= lo < hi <= size , ������ҿ�����[lo, hi)

template <typename T> class Vector{//������ģ��
protected:
	Rank _size; int _capacity; T *_elem;
	void copyFrom(T const* A, Rank lo, Rank hi);//���ڸ��Ƶ�����������
	void expand();//����
	void shrink();//����
	bool bubble(Rank lo, Rank hi);//ɨ�轻��
	void bubbleSort(Rank lo, Rank hi);//ð������
	//void 
	//Rank max(Rank lo, Rank hi)
public:
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)//����c����ģs����ʼֵv
	{
		_elem = new T[_capacity = c]; for (_size = 0; _size < s; _elem[_size++] = v);
	}
	~Vector() { delete[] _elem; }
	Rank size() const { return _size; }
	bool empty() const { return !_size; }

	T& operator[](Rank r)const;  //�����±������
	Vector<T>& operator = (Vector<T> const&);//���ظ�ֵ������

	Rank insert(Rank r, T const& e);//����Ԫ��
	Rank insert(T const& e) { return insert(_size, e); }//����λ��ȱʡ��Ĭ����ΪĩԪ�ز���
	void permute(void);
	void sort(Rank lo, Rank hi, int sortMethod);//��[lo,hi)����

	//find():���������Ĳ��ң�search():���������Ĳ���
	Rank find(T const&e) { return find(e, 0, _size); }
	Rank find(T const&e, Rank lo, Rank hi)const;
	Rank search(T const&e) { return search(e, 0, _size); }
	Rank search(T const&e, Rank lo, Rank hi)const;

	//����
	void traverse( void(*visit) (T&) );//ʹ�ú���ָ��
	template <typename VST> void traverse(VST&);//ʹ�ú�������
};


//������ඨ��д��vector_implementation.h
#include "vector_implementation.h"


