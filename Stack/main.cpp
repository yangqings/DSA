#include "../UPrint/print.h"
#include "../UPrint/pch.h"
#include "stack.h"
#include <time.h>
#include <iostream>
#include "convert.h" 

using namespace std;

int main(int argc,char* argv[])
{
	int n;
	Stack <int> S;
	cout << "DSA: Stack!\n";
	cout << "Please input the number of element:";
	cin >> n;
	srand((unsigned)time(0));//改变随机种子的值
	for (int i = 0; i < n; i++)
	{
		S.push(rand()%100);
	}
	print(S);
	for (int i = 0; i < n; i++)
	{
		S.pop();
		print(S);
	}
	//if (2 > argc) { printf("%s\n", argv[0]); return 1; }
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
