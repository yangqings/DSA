// BinTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "BinNode.h"
#include "BinTree.h"
#include "../Vector/rand.h"
#include "../UPrint/print.h"


using namespace std;

template <typename T>
bool randomBinTree(BinTree<T>& bt, BinNodePosi(T) x, int h) 
{
	if (0 >= h)return false;
	if (0 < randn(h))
		randomBinTree(bt, bt.insertAsLC(x, randn((T)h * h * h)), h - 1);
	if (0 < randn(h))
		randomBinTree(bt, bt.insertAsRC(x, randn((T)h * h * h)), h - 1);
	return true;
}

//生成高度为h的测试二叉树
template <typename T> 
void testBinTree(int h)
{
	cout << "\n====BinTreeTest! Generate a binTree of height: " << h<<endl;
	BinTree<T> bt;
	bt.insertAsRoot(randn((T) h*h));print(bt);
	randomBinTree<T>(bt, bt.root(), h); print(bt);
	cout << "\n traversal: \n";
	bt.travIn	( Double<T>() ); print(bt);//中序遍历，倍乘操作
	bt.travLevel( Increase<T>() ); print(bt);//层次遍历，加操作

}

int main(int argc,char* argv[])
{
	//if (2 > argc) { cout << "Usage:" << argv[0] << " <size of BinTree Test>\a\a\n"; return 1; }
	srand((unsigned)time(NULL));//改变随机种子的值
    cout << "BinTree Test!\n"; 
	testBinTree<int> (atoi(argv[1]));

	return 0;
}

