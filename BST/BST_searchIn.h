#pragma once


template <typename T> //以v为根节点的bst子树查找关键码e
static BinNodePosi(T) & searchIn(BinNodePosi(T) v, const T &e, BinNodePosi(T) & hot)
{
	if (!(v) || (e) == (v->data)) return v;//根节点命中，或者根节点为空
	hot = v;//指向最后一个失败节点
	while (1) {
		BinNodePosi(T) & c = (e < hot->data) ? hot->lc : hot->rc;
		if (!(c) || (e) == (c->data))return c;
		hot = c;//指向最后一个失败节点,注意hot的位置
	}
}