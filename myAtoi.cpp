int myAtoi(char* s)
{
	int num = 0;
	int flag = 1;
	char* p = s;
	while (*p == ' ')//����ǰ��Ŀո�
	{
			p++;
	}
	if (*p == '+' || *p == '-')//�ж�������
	{
		flag = *p == '+' ? 1 : -1;
		p++;
	}	
	if (isalpha(*p)) return 0;

	while (isdigit(*p) && *p != '\0')
	{
		int r = *p - '0';//��¼���ֵ�λ�� 
		//�ж����
		if (num > INT_MAX / 10 || (num == INT_MAX / 10) && r > 7)
			return flag > 0 ? INT_MAX : INT_MIN;
		num = num * 10 + (*p - '0');
		p++;
	}
	return flag > 0 ? num : -num;
}
