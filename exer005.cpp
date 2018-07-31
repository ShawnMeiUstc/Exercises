/*
 * 合并数组
 *
 * 题目：合并两个排序的整数数组A和B变成一个新的数组。
 * 比如，给出A=[1,2,3,4]，B=[2,4,5,6]，返回 [1,2,2,3,4,4,5,6]。
 * 注意，这里假设A有足够空间能够容得下B，并且数组A和B的初始元素个数分别为m和n。
 *
 * 思路：先计算好复制后的元素数量，从后向前比较两数组元素，谁的元素较大，就复制到A，并递减序号，
 * 注意考虑某一序列提前复制完毕的情况
 */

#include<iostream>

using namespace std;

class solution
{
public:
	void merge_array(int* arr1, int len1, int* arr2, int len2)
	{
		if (arr1 == nullptr || arr2 == nullptr || len1 <= 0 || len2 <= 0)
			return;
		int i = len1 - 1;
		int j = len2 - 1;
		int k = len1 + len2 - 1;
		while (i >= 0 && j >= 0)
		{
			if (arr1[i] > arr2[j])
				arr1[k--] = arr1[i--];
			else
				arr1[k--] = arr2[j--];
		}

		if (i < 0)  //如果arr1先复制完完，则arr2中还有元素未复制，要单独处理
		{
			for (int p = 0; p <= j; ++p)
				arr1[p] = arr2[p];
		}

		for (int q = 0; q != len1 + len2; ++q)
		{
			cout << arr1[q] << " ";
		}
		cout << endl;
	}
};

void main()
{
	int arr1[10] = { 1,2,3,4 }, arr2[5] = { 1,2,3,4,5 };
	solution().merge_array(arr1, 4, arr2, 5);
	cin.get();
}