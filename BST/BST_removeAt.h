#pragma once

template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T) & x, BinNodePosi(T) & hot)
{
	BinNodePosi(T) w = x;
	BinNodePosi(T) succ = NULL;
	if(!HasLChild(*x))//无左子树
		succ = x = x->rc;
	else if(!HasRChild(*x))//无右子树
		succ = x = x->lc;
	else { //存在左右子树
		w = w->succ();
		swap(x->data, w->data);
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc;
	}
	hot = w->parent;//记录实际被删除节点的父节点
	if (succ) succ->parent = hot;//被删除节点的子节点与相应父节点相连
	release(w->data);
	release(w);
	return succ;
}