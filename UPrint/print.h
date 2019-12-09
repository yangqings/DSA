#pragma once

#include <stdio.h>
#include "../BinTree/BinNode.h"
#include "../BinTree/BinTree.h"

template <typename T> static void print(T* x) { x ? print(*x) : printf("<NULL>"); }
template <typename T> static void print(T& x) { UniPrint::p(x); }
template <typename T> static void print(const T& x) { UniPrint::p(x); }

//通用数据结构显示类模板
class UniPrint {
public:
	static void p(int);
	static void p(float);
	static void p(double);
	static void p(char);

	template <typename T> static void p(BinNode<T>&);
	template <typename T> static void p(BinTree<T>&);

	//static void p(HuffChar&); //Huffman（超）字符
	//static void p(VStatus); //图顶点的状态
	//static void p(EType); //图边的类型
	template <typename T> static void p(T&); //支持traverse()操作的线性结构，向量和列表
	template <typename T> static void p(T* s)//指针转为引用
	{
		s ? p(*s) : print("<NULL>");
	}
};

#include "../UPrint/print_implementation.h"
