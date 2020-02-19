#pragma once
//所有引用的头文件在此处声明
#include <iostream>
#include "../Bitmap/bitmap.h"
#include "../Dictionary/dictionary.h"
#include "../Entry/entry.h"

using namespace std;

template <typename K, typename V> //key 、value  散列表（哈希表）
class Hashtable:public Dictionary<K,V>
{
	friend class Uniprint;//友元类，允许访问私有数据
private:
	Entry<K, V>** ht; // 指向指针的指针变量  桶数组、存放词条指针
	int M;//通数组 
	int N;//词条数量
	Bitmap* lazyRemoval; //惰性删除标记

#define  lazilyRemoved(x) (lazyRemoval->test(x))
#define  markAsRemoved(x) (lazyRemoval->set(x))
protected:
	int probe4Hit(const K& k);//循关键码K对应的查找链，找到词条匹配的桶
	int probe4Free(const K& k);//循关键码k对应的查找链，找到首个可用的空桶
	void rehash(); //

public:
	Hashtable(int c = 5);
	~Hashtable();

	int size()const { return N; }
	bool put(K, V);
	V* get(K k);
	bool remove(K k);

};

#include "Hashtable_implementation.h"