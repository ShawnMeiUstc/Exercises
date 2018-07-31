// 矩阵中的路径

// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“BFCE”的路径。但矩阵中不
// 包含字符串“ABFB”的路径，因为字符串的第一个字符B占据了矩阵中的第一行
// 第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

// 思路：任选矩阵中的一个格子作为起点（起点从（0，0）开始遍历）。假设某个格子字符为ch，且这个格子
// 对应字符路径上的第i个字符。如果第i个字符不是ch，回溯一个格子；如果第i个字符恰好是ch，则到相邻的
// 格子寻找第i+1个字符；重复以上过程，直到找到正确路径或遍历所有路径。
// 由于路径不能重复进入矩阵的格子，所以用和字符矩阵大小一样的bool矩阵来标示每个字符是否已经
// 在路径中


#include <vector>
#include <iostream>

using namespace std;

class solution
{
public:
	bool has_path(vector<char> matrix, int rows, int cols, const char* str)
	{
		if (!matrix.size() || rows < 1 || cols < 1 || !str)
			return false;
		vector<bool> visited(matrix.size(), false);
		int path_len = 0;

		for (int row = 0; row < rows; ++row)
		{
			for (int col = 0; col < cols; ++col)
			{
				if (find_path(matrix, visited, path_len, rows, cols, row, col, str))
				{
					return true;
				}
			}
		}
		return false;

	}

	bool find_path(vector<char> matrix, vector<bool> visited, int& path_len,
		int rows, int cols, int row, int col, const char* str)
	{
		if (str[path_len] == '\0')
			return true;

		bool find_the_path = false;
		if (row >= 0 && row < rows &&col >= 0 && col < cols &&
			str[path_len] == matrix[row*cols + col] && !visited[row*cols + col])
		{
			++path_len;
			visited[row*cols + col] = true;

			// 递归地检查相邻点
			find_the_path = find_path(matrix, visited, path_len, rows, cols, row, col + 1, str)
				|| find_path(matrix, visited, path_len, rows, cols, row, col - 1, str)
				|| find_path(matrix, visited, path_len, rows, cols, row + 1, col, str)
				|| find_path(matrix, visited, path_len, rows, cols, row - 1, col, str);

			if (!find_the_path)  //回溯
			{
				--path_len;  
				visited[row*cols + col] = false;
			}
		}
		return find_the_path;
	}
};

int main()
{
	vector<char> matrix = { 'a','b','t','g','c','f','c','s','j','d','e','h' };
	int rows = 3, cols = 4;
	char str1[] = "bfce";
	char str2[] = "bfcsh";
	char str3[] = "abtcedjcf";
	char str4[] = "afch";
	solution a;
	bool b1 = a.has_path(matrix, rows, cols, str1);
	bool b2 = a.has_path(matrix, rows, cols, str2);
	bool b3 = a.has_path(matrix, rows, cols, str3);
	bool b4 = a.has_path(matrix, rows, cols, str4);
	cout << boolalpha << b1 << " " << b2 << " " << b3 << " " << b4 << endl;
	system("pause");
}