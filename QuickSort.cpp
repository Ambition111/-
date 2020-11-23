//根据基准值，找到基准数据应该所在的位置，将数据在原始的空间中划分成两部分
int OneQuick(int* arr, int start, int end)		//O(n)
{
	int tmp = arr[start];		//基准数据
	int i = start, j = end;

	while (i < j)
	{
		//从后往前找比基准大的数据
		while (i < j && arr[j] >= tmp)		j--;
		arr[i] = arr[j];

		//从前往后找比基准小的数据
		while (i < j && arr[i] <= tmp)		i++;
		arr[j] = arr[i];
	}
	arr[i] = tmp;
	return i;
}

/*
	时间复杂度：O(nlog(n))
	空间复杂度：O(log(n))
	稳定性：不稳定
*/
void Quick(int* arr, int start, int end)		//O(nlog(n))
{
	//退出的条件
	if (end - start < 1)		return;

	int mid = OneQuick(arr, start, end);
	Quick(arr, start, mid - 1);		//递归处理前一段数据
	Quick(arr, mid + 1, end);		//递归处理后一段数据
}

#if 0
//空间复杂度：O(log(n))    栈使用的空间决定的
//非递归实现
void Quick2(int* arr, int start, int end)
{
	Stack st;
	InitStack(&st);
	ElemType val = { start, end };
	Push(&st, val);		//将整个数据段的起始和结束位置Push到栈中

	while (!Empty(&st))
	{
		ElemType data;
		Top(&st, &data);
		Pop(&st);

		int mid = OneQuick(arr, data.start, data.end);
		if (mid - data.start > 1)	//mid - 1 - data.start > 0		//基准的前一个数据减起始位置的数据，只剩一个数据说明这段数据处理完了(已经有序)
		{
			val.start = data.start;
			val.end = mid - 1;
			Push(&st, val);		//mid这个基准数据左边有超过1个的数据压栈
		}
		if (data.end - mid > 1)	//data.end - (mid + 1) > 0		//后一段数据
		{
			val.start = mid + 1;
			val.end = data.end;
			Push(&st, val);		//mid这个基准数据右边有超过1个的数据压栈
		}
	}

	DestroyStack(&st);
}
#endif

void QuickSort(int* arr, int len)	//为了让形参只传数组地址和数组的长度，对Quick进行一次封装 
{
	Quick(arr, 0, len - 1);
}
