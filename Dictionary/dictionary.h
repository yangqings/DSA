#pragma once

template <typename K, typename V> struct Dictionary { //字典类模板
	virtual int size() const = 0;  //词条总数
	virtual bool put(K, V) = 0;    //插入词条
	virtual V* get(K k) = 0;       //读入词条
	virtual bool remove(K k) = 0;  //删除词条
};