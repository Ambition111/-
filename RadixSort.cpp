
//C���԰˴������㷨���͵�ַ 
//https://blog.csdn.net/qq_43579888/article/details/109729794 

//��ȡ������ݵ�λ��
int GetDigit(int* arr, int len)
{
	int max = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (max < arr[i])		max = arr[i];
	}

	int digit = 0;
	while (max)
	{
		digit++;
		max /= 10;
	}

	return digit;
}

//��ȡһ��������Ӧλ���ϵ�ֵ
int GetRadix(int val, int digit)
{
	//val 1234
	int radix = val % 10;	//4
	while (digit)
	{
		val /= 10;		//123
		radix = val % 10;	//3
		digit--;
	}
	return radix;
}

/*
	ʱ�临�Ӷȣ�O(d*n)  d�ǹؼ��ֵĸ���
	�ռ临�Ӷȣ�O(n)
	�ȶ��ԣ��ȶ�
*/
void RadixSort(int* arr, int len)
{
	int maxDigit = GetDigit(arr, len);

	ListQue que[10];
	for (int i = 0; i < 10; i++)
	{
		InitListQue(&que[i]);
	}

	//���ݲ�ͬ��λ����������������
	for (int i = 0; i < maxDigit; i++)
	{
		//��arr�е���������ȡ�� i ���λ����ֵ�����Ҳ��뵽��Ӧֵ�Ķ�����
		for (int j = 0; j < len; j++)
		{
			int radix = GetRadix(arr[j], i);
			Push(&que[radix], arr[j]);
		}

		//�����еĶ��а��մ�ǰ�����˳���ֵȫ������arr��
		int index = 0;
		for (int k = 0; k < 10; k++)
		{
			while (!Empty(&que[k]))
			{
				GetHead(&que[k], &arr[index++]);
				Pop(&que[k]);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		DestroyListQue(&que[i]);
	}
}
