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
	srand((unsigned)time(0));//�ı�������ӵ�ֵ
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
