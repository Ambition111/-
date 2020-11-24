void Meger(int* arr, int len, int width, int* brr)
{
	int low1 = 0;
	int high1 = low1 + width - 1;		//high1为第一个段的结束位置下标
	int low2 = high1 + 1;
	int high2 = low2 + width > len ? len - 1 : low2 + width - 1;

	int index = 0;

	//处理有两个归并段
	while ( low2 < len)
	{
		//两个归并段都有未归并数据
		while (low1 <= high1 && low2 <= high2)
		{
			if (arr[low1] < arr[low2])		brr[index++] = arr[low1++];
			else brr[index++] = arr[low2++];
		}
		//只剩下一个归并段数据，将两个归并段剩余的数据复制到brr中
		//只会执行其中一个while循环
		while (low1 <= high1)			brr[index++] = arr[low1++];
		while (low2 <= high2)			brr[index++] = arr[low2++];

		low1 = high2 + 1;
		high1 = low1 + width - 1;
		low2 = high1 + 1;
		high2 = low2 + width > len ? len - 1 : low2 + width - 1;
	}

	//处理只剩下一个归并段的情况
	while (low1 < len)		brr[index++] = arr[low1++];

	//将brr中的数据全部复制回arr中
	for (int i = 0; i < len; i++)		arr[i] = brr[i];

}

/*
	时间复杂度：O(nlog(n))
	空间复杂度：O(n)
	稳定性：稳定
*/
void MegerSort(int* arr, int len)
{
	int* brr = (int*)malloc(sizeof(int) * len);
	assert(brr != NULL);

	// i 就是每个段当前的数据个数
	for (int i = 1; i < len; i *= 2)
	{
		Meger(arr, len, i, brr);
	}
	free(brr);
}
