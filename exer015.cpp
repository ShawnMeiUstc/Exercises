/*
 * 旋转数组的最小数字

 * 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
 * {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
 *
 * 思路：二分查找。一般情况，首元素>=尾元素，用三个指针指向首元素、尾后元素、中间元素，中间元素与首尾
 * 元素分别比较，如果首元素<=中间元素，最小元素在后边，中间指针变首指针；如果中间元素<=尾元素，最小元素在
 * 左边，中间指针变尾后指针；特殊情况1：旋转0项，数组有序，直接返回第一项；特殊情况2：数组中大量重复元素，导致
 * 出现首元素=中间元素=尾元素，这时只能在这一区间顺序查找。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		if (!rotateArray.size())
			return 0;

		int fi = 0, la = int(rotateArray.size()) - 1, mid = 0;
		
		//如果未旋转，返回第一个元素
		while (rotateArray[fi] >= rotateArray[la]) 
		{
			if (la - fi == 1)
			{
				mid = la;
				break;
			}

			mid = (fi + la) >> 1;
			if (rotateArray[fi] == rotateArray[mid] &&
				rotateArray[mid] == rotateArray[la])
			{
				int min = rotateArray[0];
				for (int i = 1; i != rotateArray.size(); ++i)
				{
					if (rotateArray[i] < min)
						min = rotateArray[i];
				}
				return min;
			}
			else
			{
				if (rotateArray[fi] <= rotateArray[mid])
				{
					fi = mid;
				}
				else
				{
					la = mid;
				}
			}

		}
		return rotateArray[mid];
	}
};


int main()
{
	vector<int> v1{ 1,1,0,1,1 }, v2{ 1,0,1,1,1 }, v3{ 1,1,1,0,1 }, v4{ 0,1,1,1,1 };
	Solution a;
	cout << a.minNumberInRotateArray(v1) << " " << a.minNumberInRotateArray(v2) << " "
		<< a.minNumberInRotateArray(v3) << " " << a.minNumberInRotateArray(v4) << endl;
	system("pause");
}
