//��ʮ��������ת��2~36������Ƶ��ַ���
void Reverse_Str(char *str)//�ַ�������
{
    char tmp;
    int len = strlen(str);
    for(int  i = 0;i < len/2;i++)
    {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1- i] = tmp;
    }
}
void Myitoa(char *str,int n,int radix)//radix(����)��2~36֮��
{
    char *strlist = "0123456789abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    do
    {
        str[i++] = strlist[n%radix];
        n /= radix;
    }while(n != 0);
    str[i] = '\0';
    Reverse_Str(str);
}
