#pragma once

template <typename T> int BinNode<T>::size() {
	int s = 1;
	if (lc) s += lc->size();
	if (rc) s += rc->size();
	return s;
}

template <typename T>
BinNodePosi(T) insetAsLC(T const& e){

}

template <typename T>
BinNodePosi(T) insertAsRC(T const& e) {

}

template <typename T>
BinNodePosi(T) succ() {

}