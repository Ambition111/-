/*
	ʱ�临�Ӷȣ�O(n^2)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ��ȶ�
*/
void InsertSort(int* arr, int len)
{
	for (int i = 1; i < len; ++i)		// i ��������������ݶ�
	{
		int tmp = arr[i];
		int j = 0;
		for (j = i - 1; j >= 0; --j)
		{
			if (arr[j] <= tmp)
				break;

			arr[j + 1] = arr[j];
		}

		arr[j + 1] = tmp;
	}
}
