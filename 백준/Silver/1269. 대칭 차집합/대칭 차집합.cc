#include <iostream>
#include <set>

using namespace std;
int main()
{
	set<int> a, b;

	int aCount, bCount;
	cin >> aCount >> bCount;
	
	int temp;
	for (int i = 0; i < aCount; ++i)
	{
		cin >> temp;
		a.insert(temp);
	}

	for (int i = 0; i < bCount; ++i)
	{
		cin >> temp;
		b.insert(temp);
	}

	int hapCount = 0;

	set<int>* min = aCount > bCount ? &b : &a;
	set<int>* max = aCount > bCount ? &a : &b;
	for (auto iter = max->begin(); iter != max->end(); ++iter)
	{
		if (min->find(*iter) != min->end())
		{
			++hapCount;
		}
	}

	cout << aCount + bCount - hapCount - hapCount;

	return 0;
}