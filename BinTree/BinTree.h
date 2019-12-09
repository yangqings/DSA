#pragma once
#include "BinNode.h"

//二叉树模板类
template <typename T> class BinTree {
protected:
	int _size; BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T)x);
	void updateHeightAbove(BinNodePosi(T) x);

public:
	BinTree():_size(0),_root(NULL){}
	~BinTree(){if(0<_size)remove(_root) }
	int size()const { return _size; }
	bool empty()const { return !_root; }

	BinNodePosi(T) insertAsRoot(T const& e);
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);//作为左孩子节点接入
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);//作为右孩子节点接入
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &S);//作为左子树接入
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &S);//作为右子树接入

	int remove(BinNodePosi(T) x);//删除以节点x为根的子树
	template <typename VST>
	void travLevel(VST& visit) { if (_root)_root->travLevel(visit); }//层次遍历
	template <typename VST>
	void travIn(VST& visit) { if (_root)_root->travIn(visit); }//中序遍历

};

#include "BinTree_implementation.h"