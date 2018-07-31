/*
 * 1.青蛙跳台阶
 *
 * 问题： 青蛙一次可以跳一级台阶，也可以跳两级，
 * 问跳到n级台阶有多少种不同跳法
 *
 * 思路：n级台阶有f(n)种跳法，第一次跳时有两种选择跳一级，
 * 此时跳法数等于后面n-1级台阶的跳法数目f(n-1)，第一次跳
 * 时跳两级，此时跳法数目等于后面n-2阶台阶的跳法数目f(n-2)，
 * 有f(n) = f(n-1) + f(n-2)，初始条件f(1) = 1，f(2) = 2。
 * 
 * 2.矩形覆盖问题
 *
 * 问题：用2*1的小矩形横着或竖着去覆盖2*n的大矩形（长度为2的边竖直摆放），
 * 有多少种覆盖方法。
 *
 * 思路：总的覆盖方法为f(n)，第一个矩形有两种摆放方法：竖着放，则右边还剩2*(n-1)的矩形，
 * 覆盖方法为f(n-1)；横着放，则左下角必须再横着放一个小矩形，此时剩下2*(n-2)的矩形，覆盖方法
 * 为f(n-2)；所以有f(n) = f(n-1) + f(n-2)，同上解法。
 */

#include <iostream>

using namespace std;

class solution
{
public:
	long long frog_jump(int n)
	{
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		long long fibn = 0, fib_minus_2 = 1, fib_minus_1 = 2;
		while (n >= 3)
		{
			fibn = fib_minus_1 + fib_minus_2;
			fib_minus_2 = fib_minus_1;
			fib_minus_1 = fibn;
			--n;
		}
		return fibn;
	}
};

int main()
{
	for (int i = 1; i != 20; ++i)
	{
		cout << "台阶数： " << i << "  跳法： " << solution().frog_jump(i) << endl;
	}
	system("pause");
}