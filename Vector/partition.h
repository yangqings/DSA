#pragma once

template <typename T>
Rank Vector<T>::partition(Rank lo, Rank hi) {//轴点构造算法基础版本
	swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
	T pivot = _elem[lo];
}