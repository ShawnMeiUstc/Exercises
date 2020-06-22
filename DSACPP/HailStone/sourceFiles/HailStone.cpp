#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned int n;
	while (cin >> n)
	{
		unsigned int len = 0;
		while (1 < n)
		{
			(n % 2) ? (n = 3 * n + 1) : (n = n / 2);
			++len;
		}

		cout << len << endl;
	}
	system("pause");
}