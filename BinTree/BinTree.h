#pragma once
#include "BinNode.h"

//������ģ����
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
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);//��Ϊ���ӽڵ����
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);//��Ϊ�Һ��ӽڵ����
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &S);//��Ϊ����������
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &S);//��Ϊ����������

	int remove(BinNodePosi(T) x);//ɾ���Խڵ�xΪ��������
	template <typename VST>
	void travLevel(VST& visit) { if (_root)_root->travLevel(visit); }//��α���
	template <typename VST>
	void travIn(VST& visit) { if (_root)_root->travIn(visit); }//�������

};

#include "BinTree_implementation.h"