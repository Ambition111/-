/*
	ʱ�临�Ӷȣ�O(n^2)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ����ȶ�
*/

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectSort(int* arr, int len)
{		
	for (int i = 0; i < len - 1; ++i)
	{	
		int max_index = 0;  //���ֵ���±�
		for (int j = 0; j < len - i; ++j)
		{
			if (arr[j] > arr[max_index])
			{
				max_index = j;
			}
		}
		Swap(&arr[max_index], &arr[len - 1 - i]);  //����ǵ����ֵ�뵱ǰ���һ��Ԫ�ؽ���
	}
}
