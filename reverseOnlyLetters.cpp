/*
	给定一个字符串S，返回反转后的字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

	示例 1：
	输入："ab-cd"
	输出："dc-ba"
	
	示例 2：
	输入："a-bC-dEf-ghIj"
	输出："j-Ih-gfE-dCba"
*/ 

char * reverseOnlyLetters(char * S){
    int i = 0;
    int j = strlen(S) - 1;

    while (i < j)
    {
        if (!isalpha(S[i]))     ++i;
        if (!isalpha(S[j]))     --j;
        if (isalpha(S[i]) && isalpha(S[j]))
        {
            char tmp = S[i];
            S[i] = S[j];
            S[j] = tmp;
            ++i;
            --j;
        }
    }
    return S;
}
