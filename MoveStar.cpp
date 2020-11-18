/*
	要求将字符串里的'*'全部移动到字符串前面，并保持原来的顺序。并输出非字符的个数 
	例如： ab**bh**tbj**i*po
		输出：10，并且字符串为 *******abbhtbjipo 

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
