void Meger(int* arr, int len, int width, int* brr)
{
	int low1 = 0;
	int high1 = low1 + width - 1;		//high1Ϊ��һ���εĽ���λ���±�
	int low2 = high1 + 1;
	int high2 = low2 + width > len ? len - 1 : low2 + width - 1;

	int index = 0;

	//�����������鲢��
	while ( low2 < len)
	{
		//�����鲢�ζ���δ�鲢����
		while (low1 <= high1 && low2 <= high2)
		{
			if (arr[low1] < arr[low2])		brr[index++] = arr[low1++];
			else brr[index++] = arr[low2++];
		}
		//ֻʣ��һ���鲢�����ݣ��������鲢��ʣ������ݸ��Ƶ�brr��
		//ֻ��ִ������һ��whileѭ��
		while (low1 <= high1)			brr[index++] = arr[low1++];
		while (low2 <= high2)			brr[index++] = arr[low2++];

		low1 = high2 + 1;
		high1 = low1 + width - 1;
		low2 = high1 + 1;
		high2 = low2 + width > len ? len - 1 : low2 + width - 1;
	}

	//����ֻʣ��һ���鲢�ε����
	while (low1 < len)		brr[index++] = arr[low1++];

	//��brr�е�����ȫ�����ƻ�arr��
	for (int i = 0; i < len; i++)		arr[i] = brr[i];

}

/*
	ʱ�临�Ӷȣ�O(nlog(n))
	�ռ临�Ӷȣ�O(n)
	�ȶ��ԣ��ȶ�
*/
void MegerSort(int* arr, int len)
{
	int* brr = (int*)malloc(sizeof(int) * len);
	assert(brr != NULL);

	// i ����ÿ���ε�ǰ�����ݸ���
	for (int i = 1; i < len; i *= 2)
	{
		Meger(arr, len, i, brr);
	}
	free(brr);
}
