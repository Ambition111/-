/*
	给定一个仅包含大小写字母和空格' '的字符串 s，返回其最后一个单词的长度。
	如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
	如果不存在最后一个单词，请返回 0。
	
	示例: 
	输入: "Hello World"
	输出: 5
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
