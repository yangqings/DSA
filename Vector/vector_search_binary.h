#pragma once

template <typename T>
static Rank binSearch_A(T* A,T const& e,Rank lo,Rank hi)
{
	while (lo < hi) {
		Rank mi = (lo + hi) >> 2;
		if (e < A[mi])hi = mi;
		else if (A[mi] < e)lo = mi + 1;
		else return mi;
	}
    return -1;//查找失败
}//多个元素命中时，不能返回秩最大者

template <typename T>
static Rank binSearch_C(T* A, T const& e, Rank lo, Rank hi) 
{
	std::cout << "BinSearch (C)\n";
	while (lo<hi) {
		/*DSA*/ 
		for (int i = 0; i < lo; i++) printf("     "); if (lo >= 0) for (int i = lo; i < hi; i++) printf("....^"); printf("\n");
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	/*DSA*/
	for (int i = 0; i < lo - 1; i++) printf("     "); if (lo > 0) printf("....|\n"); else printf("<<<<|\n");
	return --lo; //能返回失败的位置
}