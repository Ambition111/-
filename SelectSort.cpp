/*
	时间复杂度：O(n^2)
	空间复杂度：O(1)
	稳定性：不稳定
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
		int max_index = 0;  //最大值的下标
		for (int j = 0; j < len - i; ++j)
		{
			if (arr[j] > arr[max_index])
			{
				max_index = j;
			}
		}
		Swap(&arr[max_index], &arr[len - 1 - i]);  //将标记的最大值与当前最后一个元素交换
	}
}
