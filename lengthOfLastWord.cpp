/*
	����һ����������Сд��ĸ�Ϳո�' '���ַ��� s�����������һ�����ʵĳ��ȡ�
	����ַ����������ҹ�����ʾ����ô���һ�����ʾ��������ֵĵ��ʡ�
	������������һ�����ʣ��뷵�� 0��
	
	ʾ��: 
	����: "Hello World"
	���: 5
*/
 
int lengthOfLastWord(char * s){
    int len = strlen(s);
    int count = 0;

    while (len > 0 && s[len - 1] == ' ')    len--;
    if (len == 0)   return 0;

    int i = len - 1;
    while (i >= 0)
    {
        if (s[i] == ' ')    return count;
        else    ++count;
        --i;
    }
    return count;
}
