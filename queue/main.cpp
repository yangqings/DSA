#include <iostream>
#include "queue.h"
#include "../UPrint/print.h"

int main()
{
	std::cout << "DSA:Queue!\n";
	Queue<int> Q;
	std::cout << "Enqueue!\n";
	for (int i = 0; i < 10; i++)
	{
		Q.enqueue(i);
		print(Q);
	}
	for (int j = 0; j < 10; j++)
	{
		Q.dequeue();
		print(Q);
	}
	return 0;
}