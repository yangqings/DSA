#include "convert.h"
#include "stack.h"

//十进制转任意进制算法 
//S:栈，保存转换结果，栈顶为最高位; n:待转换的十进制数; base:转换为base进制 
void convert(Stack<char>& S, __int64 n, int base)
{
	static char digit[]
		= { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

	while (0 < n) {
		int remainder = (int)(n % base);
		S.push(digit[remainder]);
		n /= base;
	}
}

