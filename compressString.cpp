char* compressString(char* s)
{
	if (s == NULL)
		return NULL;

	int len = strlen(s);
	if (len <= 2)
		return s;
	char* str = (char*)malloc(sizeof(char) * (2 * len));
	str[0] = s[0];
	int count = 1;
	int size = 1;
	for (int i = 1; i < len + 1; i++)
	{
		if (s[i] == s[i - 1])
			count++;
		else
		{
			int num = (int)log10(count) + size;//str的长度，如果count为100，则要转换的数字100要占3个字符，即(int)log10(count)
			size = num;
			while (count)
			{
				str[num--] = count % 10 + '0';
				count /= 10;
			}
			str[++size] = s[i];
			count = 1;
			size++;
		}	
	}
	return size >= len + 1 ? s : str;
	free(str);
}
