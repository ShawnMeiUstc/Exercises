#include <iostream>
#include <random>
#include "../headFiles/BubbleSort.h"

using namespace std;

int main()
{
	default_random_engine e;
	random_device r;
	e.seed(r());
	uniform_int_distribution<int> ui(-100, 100);
	uniform_real_distribution<float> uf(-100.f, 100.f);
	vector<int> v1(20);
	vector<float> v2(20);
	cout << "before sort v1: ";
	for (int i = 0; i != v1.size(); ++i)
	{
		v1[i] = ui(e);
		cout << v1[i] << " ";
	}
	cout << endl;

	cout << "before sort v2: ";
	for (int i = 0; i != v2.size(); ++i)
	{
		v2[i] = uf(e);
		cout << v2[i] << " ";
	}
	cout << endl;

	BubbleSort(v1);
	BubbleSort(v2);
	cout << "after sort v1: ";
	for (int i = 0; i != v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	cout << "after sort v2: ";
	for (int i = 0; i != v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	system("pause");
}
