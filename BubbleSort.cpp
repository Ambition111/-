/*
	ʱ�临�Ӷȣ�O(n^2)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ��ȶ�
*/

void BubbleSort1(int* arr, int len)
{	
	for (int i = 0; i < len - 1; ++i)
	{
		//һ��ѭ���������������ݱ��ŵ����
		for (int j = 0; j < len - 1 - i; ++j)//len - 1 - i ÿ����һ��������һ�ξͿ����ٱȽ�һ������
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void BubbleSort(int* arr, int len)//�Ż���
{
	for (int i = 0; i < len - 1; ++i)
	{
		bool flag = true;
		for (int j = 0; j < len - 1 - i; ++j)//len - 1 - i ÿ����һ��������һ�ξͿ����ٱȽ�һ������
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = false;
			}
		}
		//һ��ѭ�������flag��Ϊ�棬˵���������ݾ�����û�н��н���
		if (flag)
		{
			return;
		}
	}
}
