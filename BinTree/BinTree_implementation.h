#pragma once
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
//更新节点x的高度
template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
	return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

//更新树的高度
template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) 
{
	while (x) { updateHeight(x); x = x->parent; }
}

//空树插入根节点
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
	_size = 1; return _root = new BinNode<T> (e);
}

//作为节点x的左孩子插入
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x,T const& e)
{
	_size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc;
}
//作为节点x的右孩子插入
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x,T const& e)
{
	_size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc;
}
//S作为节点x的左子树插入
//S本身被置空
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S)
{
	x->lc = S->_root;
	x->lc->parent = x;

	_size += S->_size;
	updateHeightAbove(x);
	S->_root = NULL;
	S->size = 0; release(S); S = NULL; return x;
}
//S作为节点x的右子树插入
//S本身被置空
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S)
{
	x->rc = S->_root;
	x->rc->parent = x;

	_size += S->_size;
	updateHeightAbove(x);
	S->_root = NULL;
	S->size = 0; release(S); S = NULL; return x;
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)
{
	return 0;
}


//倍增操作器
template <typename T> struct Double
{
	virtual void operator() (T& e) const { e *= 2; }
};

//递增操作器
template <typename T> struct Increase
{
	virtual void operator() (T& e) const { e += 1; }
};