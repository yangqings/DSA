#include "convert.h"
#include "stack.h"

//ʮ����ת��������㷨 
//S:ջ������ת�������ջ��Ϊ���λ; n:��ת����ʮ������; base:ת��Ϊbase���� 
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

