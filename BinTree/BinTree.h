#pragma once
#include "BinNode.h"

//������ģ����
template <typename T> class BinTree {
protected:
	int _size; BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T)x);
	//void updateHeightAbove();



};

#include "BinTree_implementation.h"