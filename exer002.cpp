/*
* 不修改数组找出其中重复的数字
*
* 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
* 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
* 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
* 输出是重复的数字2或者3。
*
* 思路：不用辅助空间。用中间值m将元素大小一分为二，遍历数组计数大小在[1,m]中元素出现次数，
* 大于m则重复元素在[1,m]中，小于m则(m+1,n]中有重复，调整区间，继续上述操作，直到区间长度为1
*
* 复杂度：时间O(nlgn)，空间O(1)
*/

#include<iostream>
#include<cstdlib>

using namespace std;

class solution
{
public:
	void find_same_num_nochange(int arr[], int size)
	{
		if (arr == nullptr || size <= 0)
			return;

		int first = 1;
		int last = size - 1;

		while (first != last)
		{
			int mid = (first + last) >> 1; //值的中位数
			int count = 0;

			for (int i = 0; i != size; ++i)
			{
				if (arr[i] < 1 || arr[i] > size + 1)
					exit(1);

				if (arr[i] <= mid)
					++count;
			}

			if (mid < count)
			{
				last = mid;
			}
			else
			{
				first = mid + 1;
			}
		}
		cout << first << endl;
	}
};

void main()
{
	int arr[] = { 3,3,5,4,1,2,6,7 };
	solution a;
	a.find_same_num_nochange(arr, 8);
	system("pause");
}