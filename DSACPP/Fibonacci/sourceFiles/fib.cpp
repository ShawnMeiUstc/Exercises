#include <iostream>

#include "../headFiles/fibIter.h"
#include "../headFiles/fibRecur.h"

int main()
{
	int n;
	while (std::cin >> n)
	{
		std::cout << fibIter(n) << "-------";
		std::cout << fibRecur(n) << std::endl;
	}
	system("pause");
	return 0;
}