// 硬币问题
//
// 问题：我们有面值为1元3元5元的硬币若干枚，如何用最少的硬币凑够n元(n为整数，其他输入返回0)？
//
// 思路：1.动态规划——平凡情况：n <= 0, 返回0， n为1,2,3,4,5时，返回1,2,1,2,1；n >= 6时，每次最后一次拿的
// 硬币面额为1,3,5中的一种，最优解应该是前一次最优解加一，即f(n) = f(n - i) + 1;(i = 1,3,5)。
// 2.贪心算法——平凡情况：n <= 0, 返回0， n为1,2,3,4,5时，返回1,2,1,2,1；n >= 6时，尽可能先拿5元，剩下不足5
// 元，参照平凡情况。


#include <iostream>
#include  <vector>

using namespace std;

class solution
{
public:
	int coin_num_dp(int n)
	{
		if (n <= 0)
			return 0;
		if (n == 1 || n == 3 || n == 5)
			return 1;
		if (n == 2 || n == 4)
			return 2;
		vector<int> results(n + 1, 0);
		results[0] = 0;
		results[1] = results[3] = results[5] = 1;
		results[2] = results[4] = 2;
		for (int i = 6; i <= n; ++i)
		{
			results[i] = results[i - 1] + 1;
			if (results[i - 3] + 1 < results[i])
				results[i] = results[i - 3] + 1;
			if (results[i - 5] + 1 < results[i])
				results[i] = results[i - 5] + 1;
		}
		return results[n];
	}

	int coin_num_gre(int n)
	{
		if (n <= 0)
			return 0;
		if (n == 1 || n == 3 || n == 5)
			return 1;
		if (n == 2 || n == 4)
			return 2;

		int times_of_5 = n / 5;
		int result = times_of_5;
		int m = n % 5;
		switch (m)
		{
		case 1:
		case 3:
		case 5:
			result += 1;
			break;
		case 2:
		case 4:
			result += 2;
		default:
			break;
		}
		return result;

	}
};


int main()
{
	solution a;
	for (int i = 0; i != 60; ++i)
	{
		cout << a.coin_num_dp(i) << " " << a.coin_num_gre(i) << endl;
	}
	cout << endl;
	system("pause");
}