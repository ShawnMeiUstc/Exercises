/*
* 找出数组中重复的数字
*
* 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
* 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
* 那么对应的输出是重复的数字2或者3。
*
* 思路：扫描数组，位置i的值与i比较，相同跳过，不相同假设把值记为m，把m与array[m]比较，
* 相同说明重复，返回该值，不相同把m与array[m]交换
*
* 复杂度：时间O(n)，空间O(1)
*/

#include <cstdlib>
#include <iostream>

using namespace std;

class solution
{
public:
	void find_same_num(int arr[], int size)
	{
		if (arr == nullptr || size <= 0)
			return;

		for (int i = 0; i != size; ++i)
		{
			if (arr[i] < 0 || size - 1 < arr[i])
				exit(1);

			if (i != arr[i])
			{
				if (arr[i] != arr[arr[i]])
				{
					int temp = arr[i];
					arr[i] = arr[arr[i]];
					arr[arr[i]] = temp;
				}
				else
				{
					cout << arr[i] << endl;
				}
			}
		}

	}
};


int main()
{
	solution a;
	int arr[] = { 3,1,2,7,2,3,4,6 };
	a.find_same_num(arr, 8);
	system("pause");
}
