#pragma once
//�������õ�ͷ�ļ��ڴ˴�����
#include <iostream>
#include "../Bitmap/bitmap.h"
#include "../Dictionary/dictionary.h"
#include "../Entry/entry.h"

using namespace std;

template <typename K, typename V> //key ��value  ɢ�б���ϣ��
class Hashtable:public Dictionary<K,V>
{
	friend class Uniprint;//��Ԫ�࣬�������˽������
private:
	Entry<K, V>** ht; // ָ��ָ���ָ�����  Ͱ���顢��Ŵ���ָ��
	int M;//ͨ���� 
	int N;//��������
	Bitmap* lazyRemoval; //����ɾ�����

#define  lazilyRemoved(x) (lazyRemoval->test(x))
#define  markAsRemoved(x) (lazyRemoval->set(x))
protected:
	int probe4Hit(const K& k);//ѭ�ؼ���K��Ӧ�Ĳ��������ҵ�����ƥ���Ͱ
	int probe4Free(const K& k);//ѭ�ؼ���k��Ӧ�Ĳ��������ҵ��׸����õĿ�Ͱ
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