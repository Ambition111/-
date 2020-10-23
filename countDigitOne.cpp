int countDigitOne(int n)
{
    int count = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		while (tmp > 0)
		{
			if (tmp%10 == 1)
				count++;
			tmp /= 10;
		}
	}
	return count;
}
