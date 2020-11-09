void DeleteBlankFront(char *string)//删除字符串前面的空格
{
    char *p = string;
    while(*p == ' ')
    {
        p++;           //跳过前面的空格
    }
    while(*p !='\0')
    {
        *string = *p; //然后*p从不是空格开始，进行字符串拷贝，
        string++;
        p++;
    }
    *string = '\0';
}
void DeleteBlankbehind(char *string)//删除字符串后面的空格
{
    int i;
    int len = strlen(string) ;
    for(i = len-1;i>=0;i--)
    {
        if (*(string + i) == ' ')
            *(string + i) = '\0';  
    }
}
