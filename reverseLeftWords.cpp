/*
	�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
	�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
	���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
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
