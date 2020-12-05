/*
	字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
	请定义一个函数实现字符串左旋转操作的功能。
	比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
*/ 

void Reverse(char* s, unsigned int start, unsigned int end)
{
	if (s == NULL || start < 0 || end >= strlen(s) || start > end)   return;

	for (int i = start, j = end; i < j; ++i, --j)
	{
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
char* reverseLeftWords(char* s, int n) 
{
	if (s == NULL || n < 1)		return NULL;

	Reverse(s, 0, n - 1);
	Reverse(s, n, strlen(s) - 1);
	Reverse(s, 0, strlen(s) - 1);

	return s;
}
