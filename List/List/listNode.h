#pragma once
typedef int Rank;
#define NULL 0

#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode {//�б�ڵ�ģ����(˫������)
	T data; ListNodePosi(T) pred; ListNodePosi(T) succ;//��ֵ��ǰ���ڵ㡢��̽ڵ�

	//���캯��
	ListNode(){}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		:data(e), pred(p),succ(s) {}

	//�ӿ�
	ListNodePosi(T) insertAsPred(T const& e);//�ڵ�ǰ�����½ڵ�
	ListNodePosi(T) insertAsSucc(T const& e);//�ڵ������½ڵ�

};

//�Ǿ�̬��Ա�����ڲ���this��ʾָ��ú��������õĶ����ָ��
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this);//�½ڵ�ĺ���ǵ�ǰ�ڵ�,this�ǵ�ǰ�ڵ�

	//������������˳���ܷ�
	pred-> succ = x;//�ڵ��ǰ���ڵ�ĺ��ָ���½ڵ�
	pred = x;//�ڵ��ǰ��ָ���½ڵ�

	return x;//�����½ڵ��λ��
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi(T) x = new ListNode(e, this, succ);//�½ڵ��ǰ���ǵ�ǰ�ڵ�,this�ǵ�ǰ�ڵ�

	succ-> pred = x;//�ڵ�ĺ�̽ڵ��ǰ��ָ���½ڵ�
	succ = x;//�ڵ�ĺ��ָ���½ڵ�

	return x;
}



