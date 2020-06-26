#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// �ݹ�˼·���Ӻ���ǰ����s1�� s2����ַ���ȣ�����Ӵ�Ϊ��s1-1���루s2-1������Ӵ���
// ������ַ����ȣ���Ϊ��s1-1��s2���루s1��s2-1��֮�����ߡ�
int LCSRecur(std::string s1, std::string s2)
{
	int len = 0;
	int len1 = s1.length(), len2 = s2.length();
	if (!len1 || !len2)
		return 0;
	if (s1[len1 - 1] == s2[len2 - 1])
	{
		++len;
		s1.pop_back();
		s2.pop_back();
		len += LCSRecur(s1, s2);
	}
	else
	{
		std::string tmpS1 = s1.substr(0, s1.length() - 1), tmpS2 = s2.substr(0, s2.length() - 1);
		int tmplen1 = LCSRecur(tmpS1, s2);
		int tmplen2 = LCSRecur(s1, tmpS2);
		tmplen1 > tmplen2 ? len += tmplen1 : len += tmplen2;
	}
	return len;
}

// ����˼·���μ��㷨���ۣ����ĵ����棩15�£����ͼ15-8��������ͬ�ַ������Ͻǣ�
// ��ʵ���ǿ�ȥ����ͬĩ�ַ���LCS���ȣ�������ͬ�ַ�������ϣ���ʵ���ǿ���s1-1��s2���루s1��s2-1����LCS֮������
// ע���ӡLCS�빹���ʱ���ƥ��

std::vector<std::vector<int>> LCSIter(const std::string& s1, const std::string& s2)
{
	int r = s1.length() + 1, c = s2.length() + 1;
	std::vector<std::vector<int>> rec(r, std::vector<int>(c, 0));
	for (int i = 0; i != s1.length(); ++i)
	{
		for (int j = 0; j != s2.length(); ++j)
		{
			if (s1[i] == s2[j])
			{
				rec[i + 1][j + 1] = rec[i][j] + 1;
			}
			else  // ���ȡͬ������ֵ,std::max�Ƚ��������ֵʱ�������ֵ
			{
				rec[i + 1][j + 1] = std::max(rec[i + 1][j], rec[i][j + 1]);
			}
		}
	}
	return rec;
}

void printLCS(const std::vector<std::vector<int>>& rec, const std::string& s1)
{
	std::cout << "length of LCS is : " << rec.back().back() << std::endl;
	std::vector<char> res;
	int r = rec.size() - 1, c = rec[0].size() - 1;
	for (; r != 0 && c != 0; --r)
	{
		if (rec[r][c] == rec[r][c - 1]) // ���ȿ��Ƕ�Ӧ��ͬ������
		{
			--c;
			++r;
		}
		else if (rec[r][c] == rec[r - 1][c])
		{
			
		}
		else
		{
			res.push_back(s1[r - 1]);
			--c;
		}
	}
	for (auto it = res.crbegin(); it != res.crend(); ++it)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
}
