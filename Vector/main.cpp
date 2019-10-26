#include "pch.h"
#include <iostream>
#include "vector.h"
#include "rand.h"
#include "print.h"
using namespace std;
#define TEST_SIZE 20


int main(void)
{
	Vector<int> V1;
	int e;
	cout << "Vector Test!\n";
	srand((unsigned)time(0));//�ı�������ӵ�ֵ,ʹ��ÿ�β�����Ԫ�����s
	for (int i = 0; i < TEST_SIZE; i++) V1.insert(randn(100));//�������[0,100)��Χ�� TEST_SIZE ����
	print(V1);
	V1.sort(0, TEST_SIZE,1);
	print(V1);
	cout << "\nPlease input the element you want to search: ";
	cin >> e;
	//cout << e <<"\n";
	cout << V1.search(e, 0, TEST_SIZE)<<"\n";
	V1.permute();
	print(V1);
    cout << "Done!\n";
    return 0;
}