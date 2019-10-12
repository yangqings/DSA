#include "pch.h"
#include <iostream>
#include "vector.h"
#include "rand.h"
#include "print.h"
using namespace std;
#define TEST_SIZE 10

int main(void)
{
	Vector<int> V1;
	cout << "Vector Test!\n";
	for (int i = 0; i < TEST_SIZE; i++) V1.insert(randn(100));//随机插入[0,100)范围内 TEST_SIZE 个数
	print(V1);
	V1.sort(0, TEST_SIZE,1);
	print(V1);
	V1.permute();
	print(V1);
    cout << "Done!\n";
	cout << "Done!\n";
	cout << "Done!\n";
	cout << "Done!\n";
	cout << "Done!\n";
	cout << "Done!\n";
    return 0;
}