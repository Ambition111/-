int* printNumbers(int n, int* returnSize)
{
	*returnSize = pow(10, n) - 1;
	int *re = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 1; i < (pow(10, n)); i++)
	{
		re[i-1] = i;
	}
	return re;
	free(re);;
}
