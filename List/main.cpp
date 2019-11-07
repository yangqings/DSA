
#include <iostream>
#include "list.h"

template <typename T>
void randomList(List<T> & list, int n) {//生成长度为n的随机列表
	ListNodePosi(T) p = ((T)(rand() % 2)) ?
		list.insertAsLast((T)(rand() % n * 2)) :
		list.insertAsFirst((T)(rand() % n * 2));
	for (int i = 1; i < n; i++)
		p = rand() % 2 ?
		list.insertB(p, (T)(rand() % n * 2)) :
		list.insertA(p, (T)(rand() % n * 2));
}

int main()
{
    std::cout << "List Test!\n";
	List<int> La;
	srand((unsigned)time(0));//改变随机种子的值,使得每次产生的元素随机s
	randomList(La, 60);
	print(La);
	return 0;
}

