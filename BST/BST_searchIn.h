#pragma once


template <typename T> //��vΪ���ڵ��bst�������ҹؼ���e
static BinNodePosi(T) & searchIn(BinNodePosi(T) v, const T &e, BinNodePosi(T) & hot)
{
	if (!(v) || (e) == (v->data)) return v;//���ڵ����У����߸��ڵ�Ϊ��
	hot = v;//ָ�����һ��ʧ�ܽڵ�
	while (1) {
		BinNodePosi(T) & c = (e < hot->data) ? hot->lc : hot->rc;
		if (!(c) || (e) == (c->data))return c;
		hot = c;//ָ�����һ��ʧ�ܽڵ�,ע��hot��λ��
	}
}