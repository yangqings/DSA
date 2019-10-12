#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY  3 //默认容量
//向量的秩 0<= lo < hi <= size , 是左闭右开区间[lo, hi)

template <typename T> class Vector{//向量类模板
protected:
	Rank _size; int _capacity; T *_elem;
	void copyFrom(T const* A, Rank lo, Rank hi);//基于复制的向量构造器
	void expand();//扩容
	void shrink();//缩容
	bool bubble(Rank lo, Rank hi);//扫描交换
	void bubbleSort(Rank lo, Rank hi);//冒泡排序
	//void 
	//Rank max(Rank lo, Rank hi)
public:
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)//容量c，规模s，初始值v
	{
		_elem = new T[_capacity = c]; for (_size = 0; _size < s; _elem[_size++] = v);
	}
	~Vector() { delete[] _elem; }
	Rank size() const { return _size; }
	bool empty() const { return !_size; }

	T& operator[](Rank r)const;  //重载下标操作符
	Vector<T>& operator = (Vector<T> const&);//重载赋值操作符

	Rank insert(Rank r, T const& e);//插入元素
	Rank insert(T const& e) { return insert(_size, e); }//插入位置缺省，默认作为末元素插入
	void permute(void);
	void sort(Rank lo, Rank hi, int sortMethod);//对[lo,hi)排序

	//find():无序向量的查找，search():有序向量的查找
	Rank find(T const&e) { return find(e, 0, _size); }
	Rank find(T const&e, Rank lo, Rank hi)const;
	Rank search(T const&e) { return search(e, 0, _size); }
	Rank search(T const&e, Rank lo, Rank hi)const;

	//遍历
	void traverse( void(*visit) (T&) );//使用函数指针
	template <typename VST> void traverse(VST&);//使用函数对象
};


//具体的类定义写在vector_implementation.h
#include "vector_implementation.h"


