void Shell(int* arr, int len, int group)
{
	for (int i = group; i < len; ++i)		// i 负责遍历整个数据段，控制本次直接插入排序处理那一组的数据
	{
		int tmp = arr[i];
		int j = 0; 

		for (j = i - group; j >= 0; j -= group)
		{
			if (arr[j] <= tmp)
				break;

			arr[j + group] = arr[j];
		}

		arr[j + group] = tmp;
	}
}
/*
	时间复杂度：O(n^1.3 ~ n^1.5) 数学推导得出
	空间复杂度：O(1)
	稳定性：不稳定
*/
void ShellSort(int* arr, int len)
{
	int group[] = { 5, 3, 1};		//分组没有标准的分法，一般组数我们自己设置，数据量大我们可以自己加
	
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); ++i)
	{
		Shell(arr, len, group[i]);
	}
}
