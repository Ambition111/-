//���ݻ�׼ֵ���ҵ���׼����Ӧ�����ڵ�λ�ã���������ԭʼ�Ŀռ��л��ֳ�������
int OneQuick(int* arr, int start, int end)		//O(n)
{
	int tmp = arr[start];		//��׼����
	int i = start, j = end;

	while (i < j)
	{
		//�Ӻ���ǰ�ұȻ�׼�������
		while (i < j && arr[j] >= tmp)		j--;
		arr[i] = arr[j];

		//��ǰ�����ұȻ�׼С������
		while (i < j && arr[i] <= tmp)		i++;
		arr[j] = arr[i];
	}
	arr[i] = tmp;
	return i;
}

/*
	ʱ�临�Ӷȣ�O(nlog(n))
	�ռ临�Ӷȣ�O(log(n))
	�ȶ��ԣ����ȶ�
*/
void Quick(int* arr, int start, int end)		//O(nlog(n))
{
	//�˳�������
	if (end - start < 1)		return;

	int mid = OneQuick(arr, start, end);
	Quick(arr, start, mid - 1);		//�ݹ鴦��ǰһ������
	Quick(arr, mid + 1, end);		//�ݹ鴦���һ������
}

#if 0
//�ռ临�Ӷȣ�O(log(n))    ջʹ�õĿռ������
//�ǵݹ�ʵ��
void Quick2(int* arr, int start, int end)
{
	Stack st;
	InitStack(&st);
	ElemType val = { start, end };
	Push(&st, val);		//���������ݶε���ʼ�ͽ���λ��Push��ջ��

	while (!Empty(&st))
	{
		ElemType data;
		Top(&st, &data);
		Pop(&st);

		int mid = OneQuick(arr, data.start, data.end);
		if (mid - data.start > 1)	//mid - 1 - data.start > 0		//��׼��ǰһ�����ݼ���ʼλ�õ����ݣ�ֻʣһ������˵��������ݴ�������(�Ѿ�����)
		{
			val.start = data.start;
			val.end = mid - 1;
			Push(&st, val);		//mid�����׼��������г���1��������ѹջ
		}
		if (data.end - mid > 1)	//data.end - (mid + 1) > 0		//��һ������
		{
			val.start = mid + 1;
			val.end = data.end;
			Push(&st, val);		//mid�����׼�����ұ��г���1��������ѹջ
		}
	}

	DestroyStack(&st);
}
#endif

void QuickSort(int* arr, int len)	//Ϊ�����β�ֻ�������ַ������ĳ��ȣ���Quick����һ�η�װ 
{
	Quick(arr, 0, len - 1);
}
