#pragma once
//所有引用的头文件在此处声明
#include <iostream>
#include "../Bitmap/bitmap.h"
#include "../Dictionary/dictionary.h"

using namespace std;

template <typename K, typename V> //key 、value
class hashtable:public Dictionary<K,V>
{
	friend class Uniprint;//友元类，允许访问私有数据
private:

};