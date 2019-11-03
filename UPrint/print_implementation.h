#pragma once
#include "../UPrint/pch.h"

void UniPrint::p(int e) { printf("%d ", e); }
void UniPrint::p(float e) { printf("%4.1f", e); }
void UniPrint::p(double e) { printf("%4.1f", e); }
void UniPrint::p(char e) { printf("%c", (31 < e) && (e < 128) ? e : '$'); }


//typeid():����ָ���������ָ�����ʵ������
template <typename T>
void UniPrint::p(T& s) {
	printf("%s[%p]*%d:\n", typeid(s).name(), &s, s.size());
	s.traverse( print );
	printf("\n");
}
//%p���ָ���ֵַ

