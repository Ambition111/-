int subtractProductAndSum(int n)
{
	int sum = 0;
	int product = 1;
	int tmp;
	while (n > 0)
	{
		tmp = n % 10;
		sum += tmp;
		product *= tmp;
		n /= 10;
	}
	return product - sum;
}
