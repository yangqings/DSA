#pragma once

//哈希表类具体


template <typename K, typename V>
Hashtable <K, V>::Hashtable(int c) { //创建散列表
	M = primeNLT();
	N = 0;
}