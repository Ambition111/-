//将十进制数字转成2~36任意进制的字符串
void Reverse_Str(char *str)//字符串逆置
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
void Myitoa(char *str,int n,int radix)//radix(进制)在2~36之间
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
