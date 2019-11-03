#pragma once

#include <stdio.h>

template <typename T> static void print(T* x) { x ? print(*x) : printf("<NULL>"); }
template <typename T> static void print(T& x) { UniPrint::p(x); }
template <typename T> static void print(const T& x) { UniPrint::p(x); }

//ͨ�����ݽṹ��ʾ��ģ��
class UniPrint {
public:
	static void p(int);
	static void p(float);
	static void p(double);
	static void p(char);

	//static void p(HuffChar&); //Huffman�������ַ�
	//static void p(VStatus); //ͼ�����״̬
	//static void p(EType); //ͼ�ߵ�����
	template <typename T> static void p(T&); //֧��traverse()���������Խṹ���������б�
	template <typename T> static void p(T* s)//ָ��תΪ����
	{
		s ? p(*s) : print("<NULL>");
	}
};

#include "../UPrint/print_implementation.h"
