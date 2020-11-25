
//C语言八大排序算法博客地址 
//https://blog.csdn.net/qq_43579888/article/details/109729794 

//获取最大数据的位数
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

//获取一个数据相应位数上的值
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
	时间复杂度：O(d*n)  d是关键字的个数
	空间复杂度：O(n)
	稳定性：稳定
*/
void RadixSort(int* arr, int len)
{
	int maxDigit = GetDigit(arr, len);

	ListQue que[10];
	for (int i = 0; i < 10; i++)
	{
		InitListQue(&que[i]);
	}

	//根据不同的位数，处理整个数据
	for (int i = 0; i < maxDigit; i++)
	{
		//将arr中的所有数据取其 i 这个位数的值，并且插入到相应值的队列中
		for (int j = 0; j < len; j++)
		{
			int radix = GetRadix(arr[j], i);
			Push(&que[radix], arr[j]);
		}

		//将所有的队列按照从前到后的顺序把值全部出到arr中
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
