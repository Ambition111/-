/*
	����һ���ַ���S�����ط�ת����ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��

	ʾ�� 1��
	���룺"ab-cd"
	�����"dc-ba"
	
	ʾ�� 2��
	���룺"a-bC-dEf-ghIj"
	�����"j-Ih-gfE-dCba"
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
