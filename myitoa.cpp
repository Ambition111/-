char* myitoa(int num)
{
	int count = Numer(num) + 1;
	char* str = (char*)malloc(sizeof(char) * (count + 1));
	if (num == 0)//�����������Ϊ0������"0"
	{
		*str = '0';
		*(str + 1) = '\0';
		return str;
	}
	int i;
	int tmp;
	if (num < 0)//�����������Ϊ����
	{
		str[0] = '-';//�����ֵ�һ��Ԫ�ظ�ֵΪ'-'
		num = abs(num);//ȡ����ֵ��������
		i = count -1;
		while (num >  0 && i >= 1)//�Ӻ���ǰ����ģ10ȡ��λ����ֵ
		{
			tmp = num % 10;
			str[i--] = tmp + '0';
			num /= 10;
		}
		str[count] = '\0';//��'\0'��β
	}
	else//�����������Ϊ����
	{
		i = count - 2;
		while (num > 0 && i >= 0)
		{
			tmp = num % 10;
			str[i--] = tmp + '0';
			num /= 10;
		}
		str[count - 1] = '\0';
	}
	return str;
	free(str);
}
