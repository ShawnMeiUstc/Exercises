// 剪绳子
//
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
//
// 思路：1.动态规划——平凡情况，n为0,1,2,3时，返回0,0,1,2；n >= 4时，遍历所有剪法，
// 找出最大值，存入数组。由于是从下至上遍历，子问题的最优解都已保存，可以被更大的
// 问题直接使用。
// 2.贪心算法——平凡情况，n为0,1,2,3时，返回0,0,1,2；n = 4时，剪成2*2两段；当n>=5时，
// 可以证明：2(n-2) > n 和 3(n-3) > n ——即剪成两段乘积比不剪要大;又因为，3(n-3)>=2(n-2),
// 即剪成3和n-3两段要比剪成2和n-2两段乘积要大，所以尽可能剪成长度为3的段，最后肯定得到最优解。


#include <iostream>
#include <vector>

using namespace std;


class solution
{
public:
	int cut_rope_dp(int len)
	{
		if (len < 2)
			return 0;
		if (len == 2)
			return 1;
		if (len == 3)
			return 2;

		vector<int> results(len + 1, 0);
		//剩余长度为1,2,3不用剪了（0填数，不考虑）
		results[0] = 0;
		results[1] = 1;
		results[2] = 2;
		results[3] = 3;

		int max = 0;
		for (int i = 4; i <= len; ++i)
		{
			max = 0;
			for (int j = 1; j <= i >> 1; ++j)
			{
				int result = results[j]* results[i - j];
				if (result > max)
					max = result;
			}
			results[i] = max;
		}
		return results[len];
	}

	int cut_rope_gre(int len)
	{
		if (len < 2)
			return 0;
		if (len == 2)
			return 1;
		if (len == 3)
			return 2;

		int times_of_3 = len / 3;
		int times_of_2 = 0;
		if (len - times_of_3 * 3 == 1)
		{
			times_of_3 -= 1;
			times_of_2 = 2;
		}
		if (len - times_of_3 * 3 == 2)
		{
			times_of_2 = 1;
		}

		return int(pow(3, times_of_3)) * int(pow(2, times_of_2));
	}
};


int main()
{
	solution a;
	cout << a.cut_rope_dp(4) << endl;
	cout << a.cut_rope_dp(8) << endl;
	cout << a.cut_rope_dp(10) << endl;

	cout << a.cut_rope_gre(4) << endl;
	cout << a.cut_rope_gre(8) << endl;
	cout << a.cut_rope_gre(10) << endl;
	system("pause");
}