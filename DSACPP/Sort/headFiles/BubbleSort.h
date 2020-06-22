#pragma once
#include <vector>
#include <functional>

template<typename _T, typename _CompareLess = std::less<_T>>
void BubbleSort(std::vector<_T>& input, _CompareLess compLess = _CompareLess())
{
	int n = input.size();
	if (!n)
	{
		return;
	}
	for (bool sorted = false; sorted = !sorted && n >= 0; --n)
	{
		for (int i = 0; i != n - 1; ++i)
		{
			if (!compLess(input[i], input[i + 1]))
			{
				_T tmp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = tmp;
				sorted = false;
			}
		}
	}
}

