//一棵子树的调整过程
void OneAdjust(int* arr, int len, int root)	//O(logn)
{
	int tmp = arr[root];
	int i = root;
	int j = 2 * i + 1;
	while (j < len)
	{
		if (j + 1 < len && arr[j] < arr[j + 1])		// j + 1 < len 成立，则有右孩子。arr[j] < arr[j+1]左孩子小于右孩子
			j++;
		if (arr[j] < tmp)
			break;

		arr[i] = arr[j];
		i = j;
		j = 2 * i + 1;
	}

	arr[i] = tmp;
}
//创建大根堆
void CreateHeap(int* arr, int len)	//O(nlog(n))
{
	int lastRoot = (len - 2) / 2;//((len - 1) - 1) / 2 /*lastRoot就是最后一棵子树的根节点下标

	for ( int i = lastRoot; i >= 0; --i) //从lastRoot开始，循环到整棵树的根节点，调整
	{
		OneAdjust(arr, len, i);
	}
}

//堆排序
/*
	时间复杂度：O(nlog(n))
	空间复杂度：O(1)
	稳定性：不稳定
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
