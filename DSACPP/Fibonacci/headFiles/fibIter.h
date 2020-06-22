#pragma once
long long fibIter(int n)
{
	long long f = 0, g = 1;
	if (n <= 0)
	{
		return 0;
	}

	while (0 < --n)
	{
		long long tmp = f;
		f = g;
		g += tmp;
	}
	return g;
}
