#pragma once
#include <stdio.h>
#include "../BinTree/BinNode.h"
#include "../BinTree/BinTree.h"
#include "../Bitmap/bitmap.h"

template <typename T> 
static void print(T* x) { print(*x); }

static void print(char* x) { printf("%s", x ? x : "<NULL>"); }
static void print(const char* x) { printf("%s", x ? x : "<NULL>"); }


//ͨ�����ݽṹ��ʾ��ģ��
class UniPrint {
public:
	static void p(int);
	static void p(float);
	static void p(double);
	static void p(char);

	template <typename T> static void p(BinNode<T>&);
	template <typename T> static void p(BinTree<T>&);

	//static void p(HuffChar&); //Huffman�������ַ�
	//static void p(VStatus); //ͼ�����״̬
	//static void p(EType); //ͼ�ߵ�����
	template <typename T> static void p(T&); //֧��traverse()���������Խṹ���������б�
	template <typename T> static void p(T* s)//ָ��תΪ����
	{
		s ? p(*s) : printf("<NULL>");
	}
};

template <typename T> static void print(T& x) { UniPrint::p(x); }
template <typename T> static void print(const T& x) { UniPrint::p(x); }

#include "../UPrint/print_implementation.h"
