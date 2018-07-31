/*
 * 斐波那契数列
 *
 * 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
 * 
 * 思路：递归方法时间复杂度达到O(2^n)，不实用，采用迭代方法，采用中间变量
 * 记录结果，时间复杂度O(n)
 */

#include <iostream>

using  namespace std;

class solution
{
public:
	long long fib(int n)
	{
		if (n < 0)
			exit(1);

		long long fib0 = 0;
		long long fib1 = 1;
		if (n == 0)
			return fib0;
		if (n == 1)
			return fib1;

		long long fibn = 0, fib_n_minus_2 = 0, fib_n_minus_1 = 1;
		while (n >= 2)
		{
			fibn = fib_n_minus_1 + fib_n_minus_2;
			fib_n_minus_2 = fib_n_minus_1;
			fib_n_minus_1 = fibn;
			--n;
		}
		return fibn;
	}
};

int main()
{
	for (int i = 0; i != 20; ++i)
	{
		cout << solution().fib(i) << " ";
	}
	cout << endl;
	system("pause");
}