/*
	实现字符串的拷贝函数.
char *Mystrncpy(char *strDest,const char *strSource,size_t count );
其中strDest为存放目标字符串的内存, strSource为源字符串, count为拷贝的字符数量.

示例 1：输入：(buf,4,"abcde");
		输出："abcd烫...   

示例 2：输入：(buf,5,"abcde");
		输出："abcd烫... 

示例 3：输入：(buf,6,"abcde");
		输出："abcde"

示例 4：输入：(buf,7,"abcde");
		输出："abcde"
解释:会将buf的前7个字符分别设为'a','b','c','d','e','\0','\0'
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
