/*
	Ҫ���ַ������'*'ȫ���ƶ����ַ���ǰ�棬������ԭ����˳�򡣲�������ַ��ĸ��� 
	���磺 ab**bh**tbj**i*po
		�����10�������ַ���Ϊ *******abbhtbjipo 

*/ 

int MoveStar(char* str)
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] != '*')
		{
			count++;
		}
		else
		{
			int j = i;
			char tmp = str[j];
			while (j > 0 && str[j - 1] != '*')
			{
				str[j] = str[j - 1];
				j--;
			}
			str[j] = tmp;
		}
	}
	printf("%s\n", str);
	return count;
}
