/*
	����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳�� 
	ʾ����

	���룺"Let's take LeetCode contest"
	�����"s'teL ekat edoCteeL tsetnoc
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
    Reverse_startToend(s, i, j - 1);  //�������һ���ַ����ǿո�ĵ���
    return s;
}
