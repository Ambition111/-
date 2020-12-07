/* 
����һ���ַ��� s ��һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת��

1.���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
2.���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����

ʾ��:

����: s = "abcdefg", k = 2
���: "bacdfeg"
*/ 

void Reverse(char *s, int start, int end)
{
    if (s == NULL || start < 0 || end >= strlen(s) || start > end)   return;
    for (int i = start, j = end; i < j; ++i, --j)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

char * reverseStr(char * s, int k){
    int surCount = strlen(s);   //ʣ���ַ��ĸ���
    int i = 0;
    while (s[i] != '\0')
    {
        if (surCount >= (2 * k))
        {
            Reverse(s, i, i + k - 1);
            surCount -= 2 * k;
            i += 2 * k;
        }
        if (surCount < (2 * k) && surCount >= k)
        {
            Reverse(s, i, i + k - 1);
            break;
        }
        if (surCount < k)
        {
            Reverse(s, i, strlen(s) - 1);
            break;
        } 
    }
    return s;
}
