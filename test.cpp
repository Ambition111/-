#include <stdio.h>

//����һ��10���������������Ӧ�����Ƶ���1�ĸ��� 

int NumerOfBin1(unsigned n)//����һ 
{
	int count = 0;
	while (n != 0)
	{
		if (n & 1)
		{
			count++;
		}
		n >>= 1;//����2����������1 
	}
	return count;
}

int NumerOfBin2(unsigned n)//������ ��n & = n - 1
{
	int count = 0;
	while (n != 0)
	{
		n &= n - 1;//����ȥ��������n�е�һ��1������ 7&6��0111 & 0110 = 0110 
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
