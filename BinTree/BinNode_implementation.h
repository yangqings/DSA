#pragma once
#include "../queue/queue.h"

//ͳ�Ƶ�ǰ�ڵ��������ģ(�ڵ㱾��Ҳ����)
template <typename T> 
int BinNode<T>::size() {
	int s = 1;
	if (lc) s += lc->size();//�ݹ��ۼ�������
	if (rc) s += rc->size();//�ݹ��ۼ�������
	return s;
}

template <typename T>
BinNodePosi(T) insetAsLC(T const& e){
	return lc = new BinNode(e, this);//e��Ϊ���ӽڵ���뵱ǰ�ڵ�
}

template <typename T>
BinNodePosi(T) insertAsRC(T const& e) {
	return rc = new BinNode(e, this);//e��Ϊ�Һ��ӽڵ���뵱ǰ�ڵ�
}


//��λ�ڵ�ĺ�̽ڵ�
template <typename T>
BinNodePosi(T) succ() {
	//��
}


//��α���
template <typename T> template <typename VST> 
 void BinNode<T>::travLevel(VST& visit) {
	 Queue<BinNodePosi(T)> Q;
	 Q.enqueue(this);//���ڵ����
	 while (!Q.empty()) {
		 BinNodePosi(T) x = Q.dequeue;
		 if()
	 }
}