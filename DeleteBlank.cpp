void DeleteBlankFront(char *string)//ɾ���ַ���ǰ��Ŀո�
{
    char *p = string;
    while(*p == ' ')
    {
        p++;           //����ǰ��Ŀո�
    }
    while(*p !='\0')
    {
        *string = *p; //Ȼ��*p�Ӳ��ǿո�ʼ�������ַ���������
        string++;
        p++;
    }
    *string = '\0';
}
void DeleteBlankbehind(char *string)//ɾ���ַ�������Ŀո�
{
    int i;
    int len = strlen(string) ;
    for(i = len-1;i>=0;i--)
    {
        if (*(string + i) == ' ')
            *(string + i) = '\0';  
    }
}
