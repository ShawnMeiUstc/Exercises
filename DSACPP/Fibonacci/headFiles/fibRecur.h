#pragma once
long long fibRecur(int n)
{
	return (n > 1) ? fibRecur(n - 1) + fibRecur(n - 2) : n;
}
