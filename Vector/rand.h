#pragma once
#include <iostream>
#include <time.h> //通常用当前时刻设置随机种子
//生成随机数

static int randn(int range) { return rand() % range; }
static int randn(int lo, int hi) { return lo + rand() % (hi - lo); }