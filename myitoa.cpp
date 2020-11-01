char* myitoa(int num)
{
	int count = Numer(num) + 1;
	char* str = (char*)malloc(sizeof(char) * (count + 1));
	if (num == 0)//如果输入数字为0，返回"0"
	{
		*str = '0';
		*(str + 1) = '\0';
		return str;
	}
	int i;
	int tmp;
	if (num < 0)//如果输入数字为负数
	{
		str[0] = '-';//将数字第一个元素赋值为'-'
		num = abs(num);//取绝对值化成正数
		i = count -1;
		while (num >  0 && i >= 1)//从后往前依次模10取个位并赋值
		{
			tmp = num % 10;
			str[i--] = tmp + '0';
			num /= 10;
		}
		str[count] = '\0';//赋'\0'结尾
	}
	else//如果输入数字为正数
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
