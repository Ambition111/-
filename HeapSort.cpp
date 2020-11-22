//һ�������ĵ�������
void OneAdjust(int* arr, int len, int root)	//O(logn)
{
	int tmp = arr[root];
	int i = root;
	int j = 2 * i + 1;
	while (j < len)
	{
		if (j + 1 < len && arr[j] < arr[j + 1])		// j + 1 < len �����������Һ��ӡ�arr[j] < arr[j+1]����С���Һ���
			j++;
		if (arr[j] < tmp)
			break;

		arr[i] = arr[j];
		i = j;
		j = 2 * i + 1;
	}

	arr[i] = tmp;
}
//���������
void CreateHeap(int* arr, int len)	//O(nlog(n))
{
	int lastRoot = (len - 2) / 2;//((len - 1) - 1) / 2 /*lastRoot�������һ�������ĸ��ڵ��±�

	for ( int i = lastRoot; i >= 0; --i) //��lastRoot��ʼ��ѭ�����������ĸ��ڵ㣬����
	{
		OneAdjust(arr, len, i);
	}
}

//������
/*
	ʱ�临�Ӷȣ�O(nlog(n))
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ����ȶ�
*/
void HeapSort(int* arr, int len)
{
	CreateHeap(arr, len);

	for (int i = 0; i < len - 1; ++i)
	{
		Swap(&arr[0], &arr[len - 1 - i]);
		OneAdjust(arr, len - i - 1, 0);
	}
}
