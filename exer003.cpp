/*
 * 二维数组中的查找

 * 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
 * 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
 * 整数，判断数组中是否含有该整数。

 * 思路：在二维数组(维度p,q)组成的矩形中，每次取右上（或左下）角的数字m与待查找元素n比较，
 * 如果m > n，剔除最右一列元素，如果m < n，剔除最上一行，如果等于n，返回true，
 * 调整m重复以上操作，直到查找范围为空返回false，或找到待查找元素返回true。

 * 复杂度：时间O(p+q)，空间O(1)
 */

#include <iostream>

using namespace std;

class solution
{
public:
	bool find_num_in_2d_arr(int* arr, int row, int col, int num)
	{
		if (arr == 0 || row <= 0 || col <= 0)
			return false;
		int crow = 0, ccol = col - 1;
		while (crow < row && ccol >= 0)
		{
			if (arr[crow * col + ccol] > num)
			{
				--ccol;
			}
			else if (arr[crow * col + ccol] < num)
			{
				++crow;
			}
			else
				return true;
		}
		return false;
	}
};

void main()
{
	int arr[4][3] = { 1,2,3,5,6,7,8,1,2,3,4,6 };
	solution a;
	bool b = a.find_num_in_2d_arr(&arr[0][0], 4, 3, 1);
	cout << boolalpha << b << endl;
	system("pause");

}