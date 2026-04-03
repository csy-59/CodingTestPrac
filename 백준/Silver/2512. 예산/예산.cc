#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int total = 0;
	int max = 0;
	vector<int> cost(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> cost[i];
		total += cost[i];
		if (max < cost[i]) max = cost[i];
	}

	int budget;
	cin >> budget;

	if (budget > total)
	{
		cout << max;
		return 0;
	}

	sort(cost.begin(), cost.end());

	int s = 0, e = cost[n - 1];
	int result = 0, sum = 0;

	while (s <= e)
	{
		sum = 0;
		int m = (s + e) / 2;
		for (int i = 0; i < n; ++i)
		{
			sum += min(cost[i], m);
		}

		if (budget >= sum)
		{
			result = m;
			s = m + 1;
		}
		else
		{
			e = m - 1;
		}
	}

	cout << result;

	return 0;
}