#pragma once

//��ϣ�������


template <typename K, typename V>
Hashtable <K, V>::Hashtable(int c) { //����ɢ�б�
	M = primeNLT();
	N = 0;
}