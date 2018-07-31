/*
 * 替换空格
 *
 * 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
 * 则输出“We%20are%20happy.”。（假定原字符串长度足够，在原字符串上进行修改）
 *
 * 思路：先扫描一趟字符串，找出其中的空格数量，计算替换后的字符串长度，并且从后向前复制字符串，
 * 遇到空格就替换。为此需要准备两根指针，一根指向原字符串尾，一根指向新字符串尾，复制时同时移动，
 * 遇到空格原指针跳一格，新指针用于替换字符，直到两指针重合，说明空格替换完毕（此时并非一定遍历
 * 完字符串）
 * 复杂度：时间O(n)，空间O(1)
 */

#include<iostream>

using namespace std;

class solution
{
public:
	void space_substitution(char* s, int length)
	{
		if (s == nullptr || length <= 0)
			return;
		int count = 0;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (s[i] == ' ')
				++count;
		}

		if (count != 0)
		{

			int oldsize = length + 1;
			int newsize = oldsize + count * 2;

			char* p_old = &s[oldsize], *p_new = &s[newsize];

			while (p_old != p_new)
			{
				while (*p_old != ' ')
				{
					*p_new = *p_old;
					--p_old;
					--p_new;
				}
				--p_old;
				*p_new-- = '0';
				*p_new-- = '2';
				*p_new-- = '%';
			}
		}
		cout << s << endl;
	}
};

int main()
{
	char s[100] = { ' ','w','e',' ','a','r','e',' ','h','a','p','p','y',' ','\0' };
	solution().space_substitution(s, 14);
	cin.get();
}