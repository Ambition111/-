/*
	ʵ���ַ����Ŀ�������.
char *Mystrncpy(char *strDest,const char *strSource,size_t count );
����strDestΪ���Ŀ���ַ������ڴ�, strSourceΪԴ�ַ���, countΪ�������ַ�����.

ʾ�� 1�����룺(buf,4,"abcde");
		�����"abcd��...   

ʾ�� 2�����룺(buf,5,"abcde");
		�����"abcd��... 

ʾ�� 3�����룺(buf,6,"abcde");
		�����"abcde"

ʾ�� 4�����룺(buf,7,"abcde");
		�����"abcde"
����:�Ὣbuf��ǰ7���ַ��ֱ���Ϊ'a','b','c','d','e','\0','\0'
*/ 

char* Mystrncpy(char* strDest, const char* strSource, size_t count)
{
	strDest = (char*)malloc(sizeof(char) * 10);
	if (strDest == NULL)		return NULL;

	for (int i = 0; i < count; i++)
	{
		strDest[i] = strSource[i];
	}

	while (count > strlen(strSource) + 1)
	{
		strDest[count - 1] = '\0';
		count--;
	}
	return strDest;
}
