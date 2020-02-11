#pragma once
#include "../queue/queue.h"
#include "../Stack/stack.h"
/*
*BinNode状态与性质判断
*/
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (! IsRoot(x) && (& (x) == (x).parent->lc))
#define IsRChild(x) (! IsRoot(x) && (& (x) == (x).parent->rc))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x)  (HasLChild(x)||HasRChild(x))  
#define HasBothChild(x)  (HasLChild(x) && HasRChild(x))
#define HasParent(x) (!IsRoot(x))
#define IsLeaf(x) ( !HasChild(x) )

/*
*与BinNode具有特定关系的节点及其指针
*/
#define sibling(p)  \
	(IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc )
#define uncle(x)  \
	(IsLChild(* ((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)
#define FromParentTo(x)  \
	(IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->) )

//统计当前节点的子树规模(节点本身也计入)
template <typename T> 
int BinNode<T>::size() {
	int s = 1;
	if (lc) s += lc->size();//递归累加左子树
	if (rc) s += rc->size();//递归累加右子树
	return s;
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const& e){
	return lc = new BinNode(e, this);//e作为左孩子节点插入当前节点
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const& e) {
	return rc = new BinNode(e, this);//e作为右孩子节点插入当前节点
}


//定位节点的后继节点
template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
	//？
}


//层次遍历
template <typename T> template <typename VST> 
 void BinNode<T>::travLevel(const VST& visit) {
	 Queue<BinNodePosi(T)> Q;
	 Q.enqueue(this);//根节点入队
	 while (!Q.empty()) {
		 BinNodePosi(T) x = Q.dequeue();
		 visit(x->data);//取出首节点并访问

		 if ((HasLChild(*x))) Q.enqueue(x->lc);//先左孩子入队
		 if ((HasRChild(*x))) Q.enqueue(x->rc);
	 }
}

 template <typename T>//从当前节点出发，向左侧深入
 static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)>& S) {
	 while (x) { S.push(x); x = x->lc; }
 }

 //中序遍历
 template <typename T> template <typename VST>
 void BinNode<T>::travIn(const VST& visit)
 {
	 BinNodePosi(T) x = this;
	 //实现中序遍历的方法有多种
	 Stack<BinNodePosi(T)> S;//辅助栈
	 while (true)
	 {
		 goAlongLeftBranch(x, S);
		 if (S.empty())break;  //注意这句代码的位置
		 x = S.pop();
		 visit(x->data);
		 x = x->rc;//转到右子树,然后执行goAlongLeftBranch
	 }
 }


