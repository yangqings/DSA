#pragma once
#include <iostream>
#include <time.h> //ͨ���õ�ǰʱ�������������
//���������

static int randn(int range) { return rand() % range; }
static int randn(int lo, int hi) { return lo + rand() % (hi - lo); }