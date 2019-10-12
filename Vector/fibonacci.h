#pragma once

//ì³²¨ÄÇÆõÊýÁÐ 1 1 2 3 5 8 .....F(n)=F(n-1)+F(n-2)
class Fib {
private:
	int f, g;
public:
	Fib(int n) { f = 1; g = 0; while (g < n)next(); }
	int get() { return g; }
	int next() { g += f; f = g - f; return g; }
	int prev() { f = g - f; g -= f; return g; }
};