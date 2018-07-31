// 机器人的运动范围

// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子,也不能重复进入已走过的格子，例如，当k为18时，机器人能够进入方格(35, 37)，
// 因为3+5+3+7=18。但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

// 思路：从（0,0）点出发。当准备进入（i，j）时，判断能否进入，如果能进入，标记为访问过，再判断能否进入
// 相邻的四个格子。走过格子不再次进入，不回溯。

#include <iostream>
#include <vector>

using namespace std;

class solution 
{
public:
	int movingCount(int k, int rows, int cols)
	{
		vector<bool> visited(rows*cols, false);
		int count = can_move(k, rows, cols, 0, 0, visited);//从（0,0）坐标开始访问;
		return count;
	}
	//计算最大移动位置
	int can_move(int k, int rows, int cols, int row, int col, vector<bool>& visited)
	{
		int count = 0;
		if (row >= 0 && row < rows && col >= 0 && col < cols &&
			!visited[row*cols + col] && get_sum(row, col) <= k)
		{
			visited[row*cols + col] = true;
			//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
			//因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
			count = 1 + can_move(k, rows, cols, row - 1, col, visited)
				+ can_move(k, rows, cols, row, col - 1, visited)
				+ can_move(k, rows, cols, row + 1, col, visited)
				+ can_move(k, rows, cols, row, col + 1, visited);
		}
		return count;
	}

	int get_sum(int row, int col)
	{
		int row_sum = 0, col_sum = 0;
		while (row > 0)
		{
			row_sum += row % 10;
			row /= 10;
		}
		while (col > 0)
		{
			col_sum += col % 10;
			col /= 10;
		}
		return row_sum + col_sum;
	}
};

int main()
{
	cout << solution().movingCount(5, 10, 10) << endl;
	cout << solution().movingCount(10, 1, 100) << endl;
	cout << solution().movingCount(15, 20, 20) << endl;
	cout << solution().movingCount(10, 1, 10) << endl;
	cout << solution().movingCount(0, 1, 1) << endl;
	cout << solution().movingCount(-10, 1, 1) << endl;
	system("pause");
}
