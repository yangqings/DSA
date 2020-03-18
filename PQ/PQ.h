#pragma once

template <typename T> struct PQ { //优先级队列PQ模板类
	virtual void insert(T) = 0;
	virtual T getMax() = 0;
	virtual T delMax() = 0;
};
