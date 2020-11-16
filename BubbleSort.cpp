/*
	时间复杂度：O(n^2)
	空间复杂度：O(1)
	稳定性：稳定
*/

void BubbleSort1(int* arr, int len)
{	
	for (int i = 0; i < len - 1; ++i)
	{
		//一趟循环结束后，最大的数据被排到最后
		for (int j = 0; j < len - 1 - i; ++j)//len - 1 - i 每经过一趟排序，下一次就可以少比较一个数据
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void BubbleSort(int* arr, int len)//优化后
{
	for (int i = 0; i < len - 1; ++i)
	{
		bool flag = true;
		for (int j = 0; j < len - 1 - i; ++j)//len - 1 - i 每经过一趟排序，下一次就可以少比较一个数据
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = false;
			}
		}
		//一趟循环走完后，flag还为真，说明本来数据就有序，没有进行交换
		if (flag)
		{
			return;
		}
	}
}
