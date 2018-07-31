// 跳跃游戏
//
// 题目：
// 给定一个非负整数数组，您最初定位在数组的第一个索引处。
// 数组中的每个元素表示该位置的最大跳转长度。
// 您的目标是以最小跳跃次数到达最后一个索引。
// 例：
// 输入：[2, 3, 1, 1, 4]
// 输出： 2
// 说明：到达最后一个索引的最小跳转次数为2。
// 从索引0跳转1步到1，然后从最后一个索引跳3步。
// 注意：
// 您可以假设您始终可以访问最后一个索引。
//
// 思路：1.动态规划——最后一步跳跃次数等于前一步跳跃次数+1，能
// 一步完成的跳跃满足该元素的下标数+数值 >= 最后一个元素下标数。
// 2.贪心算法——每经过一次跳跃都会得到可达范围，维护两个指标来标示
// 可到达的范围，当可到达范围超过或等于数组边界，返回步数。


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jump_dp(vector<int>& nums)
	{
		int index = int(nums.size()) - 1;
		if (index < 0)
			return 0;

		vector<int> result(nums.size(), 0);
		result[0] = 0;
		result[1] = 1;
		for (int i = 2; i <= index; ++i)
		{
			int min = 1000000;
			for (int j = 0; j < i; ++j)
			{
				if (j + nums[j] >= i)
				{
					result[i] = result[j] + 1;
					if (min > result[i])
						min = result[i];
				}
			}
			result[i] = min;
		}
		return result[index];
	}

	int jump_gre(vector<int>& nums)
	{
		if (nums.size() <= 1)
			return 0;

		int beg = 1, end = nums[0]+1, step = 1; // end类似尾后迭代器
		while (end < nums.size())
		{
			++step;
			int max = end;
			for (int i = beg; i != end; ++i)
			{
				if (nums[i] + i > max)
					max = nums[i]+i;
			}
			beg = end;
			end = max+1;
		}

		return step;
	}
};

int main()
{
	vector<int> nums = { 2,3,1,1,4 };
	cout << Solution().jump_dp(nums) << endl;
	cout << Solution().jump_gre(nums) << endl;
	cin.get();
}