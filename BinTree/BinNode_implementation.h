#pragma once
#include "../queue/queue.h"

//统计当前节点的子树规模(节点本身也计入)
template <typename T> 
int BinNode<T>::size() {
	int s = 1;
	if (lc) s += lc->size();//递归累加左子树
	if (rc) s += rc->size();//递归累加右子树
	return s;
}

template <typename T>
BinNodePosi(T) insetAsLC(T const& e){
	return lc = new BinNode(e, this);//e作为左孩子节点插入当前节点
}

template <typename T>
BinNodePosi(T) insertAsRC(T const& e) {
	return rc = new BinNode(e, this);//e作为右孩子节点插入当前节点
}


//定位节点的后继节点
template <typename T>
BinNodePosi(T) succ() {
	//？
}


//层次遍历
template <typename T> template <typename VST> 
 void BinNode<T>::travLevel(VST& visit) {
	 Queue<BinNodePosi(T)> Q;
	 Q.enqueue(this);//根节点入队
	 while (!Q.empty()) {
		 BinNodePosi(T) x = Q.dequeue;
		 if()
	 }
}