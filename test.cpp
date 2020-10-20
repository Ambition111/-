#include <stdio.h>

//输入一个10进制整数，输出对应二进制的中1的个数 

int NumerOfBin1(unsigned n)//方法一 
{
	int count = 0;
	while (n != 0)
	{
		if (n & 1)
		{
			count++;
		}
		n >>= 1;//除以2，丢掉最后的1 
	}
	return count;
}

int NumerOfBin2(unsigned n)//方法二 ：n & = n - 1
{
	int count = 0;
	while (n != 0)
	{
		n &= n - 1;//可以去掉二进制n中的一个1，例如 7&6：0111 & 0110 = 0110 
		count++;
	}
	return count;
}
int main()
{
	printf("%d\n", NumerOfBin1(7));
	printf("%d\n", NumerOfBin1(255));
	printf("%d\n", NumerOfBin1(-1));
	return 0;
} 
