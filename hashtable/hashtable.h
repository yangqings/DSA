#pragma once
//�������õ�ͷ�ļ��ڴ˴�����
#include <iostream>
#include "../Bitmap/bitmap.h"
#include "../Dictionary/dictionary.h"

using namespace std;

template <typename K, typename V> //key ��value
class hashtable:public Dictionary<K,V>
{
	friend class Uniprint;//��Ԫ�࣬�������˽������
private:

};