//一维数组前缀和
void Sum(int *num, int size)
{
	int* rtsum = (int*)malloc(sizeof(int) * size);
	rtsum[0] = num[0];
	for (int i = 1; i < size; i++)
	{
		rtsum[i] = rtsum[i - 1] + num[i];
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", rtsum[i]);
	}
	free(rtsum);
}
