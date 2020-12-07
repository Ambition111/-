/* 
给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

1.如果剩余字符少于 k 个，则将剩余字符全部反转。
2.如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"
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
    int surCount = strlen(s);   //剩余字符的个数
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
