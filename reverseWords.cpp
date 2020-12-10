/*
	给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。 
	示例：

	输入："Let's take LeetCode contest"
	输出："s'teL ekat edoCteeL tsetnoc
*/ 

void Reverse_startToend(char* s, int start, int end)
{
    for (int i = start, j = end; i < j; ++i, --j)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

char * reverseWords(char * s){
    int i = 0;
    int j = i;
    if (s[j] == '\0')   return s;
    while (s[j] != '\0')
    {
        if (s[j] == ' ')
        {
            Reverse_startToend(s, i, j - 1);
            j = j + 1;
            i = j;
        }
        ++j;
    }
    Reverse_startToend(s, i, j - 1);  //处理最后一个字符不是空格的单词
    return s;
}
