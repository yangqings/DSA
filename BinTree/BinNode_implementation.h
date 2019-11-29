#pragma once
#include "../queue/queue.h"
#include "../Stack/stack.h"
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x)  (HasLChild(x)||HasRChild(x))  
#define HasBothChild(x)  (HasLChild(x) && HasRChild(x))

//ͳ�Ƶ�ǰ�ڵ��������ģ(�ڵ㱾��Ҳ����)
template <typename T> 
int BinNode<T>::size() {
	int s = 1;
	if (lc) s += lc->size();//�ݹ��ۼ�������
	if (rc) s += rc->size();//�ݹ��ۼ�������
	return s;
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const& e){
	return lc = new BinNode(e, this);//e��Ϊ���ӽڵ���뵱ǰ�ڵ�
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const& e) {
	return rc = new BinNode(e, this);//e��Ϊ�Һ��ӽڵ���뵱ǰ�ڵ�
}


//��λ�ڵ�ĺ�̽ڵ�
template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
	//��
}


//��α���
template <typename T> template <typename VST> 
 void BinNode<T>::travLevel(VST& visit) {
	 Queue<BinNodePosi(T)> Q;
	 Q.enqueue(this);//���ڵ����
	 while (!Q.empty()) {
		 BinNodePosi(T) x = Q.dequeue();
		 visit(x->data);//ȡ���׽ڵ㲢����

		 if ((HasLChild(*x))) Q.enqueue(x->lc);//���������
		 if ((HasRChild(*x))) Q.enqueue(x->rc);
	 }
}

 template <typename T>//�ӵ�ǰ�ڵ���������������
 static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)>& S) {
	 while (x) { S.push(x); x = x->lc; }
 }

 //�������
 template <typename T> template <typename VST>
 void BinNode<T>::travIn(VST& visit)
 {
	 //ʵ����������ķ����ж���
	 Stack<BinNodePosi(T)> S;//����ջ
	 while (true)
	 {
		 goAlongLeftBranch(this, S);
		 if (S.empty())break;  //ע���������λ��
		 this = S.pop();
		 visit(this->data);
		 this = this->rc;//ת��������,Ȼ��ִ��goAlongLeftBranch
	 }
 }


