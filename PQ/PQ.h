#pragma once

template <typename T> struct PQ { //���ȼ�����PQģ����
	virtual void insert(T) = 0;
	virtual T getMax() = 0;
	virtual T delMax() = 0;
};
