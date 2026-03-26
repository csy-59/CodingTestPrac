#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first != b.first)
		return a.first < b.first;

	return a.second < b.second;
}

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i].first >> v[i].second;
		}

		sort(v.begin(), v.end(), cmp);

		int result = 0;
		int min = n + 1;
		for (int i = 0; i < n; ++i)
		{
			if (v[i].second < min)
			{
				++result;
				min = v[i].second;
			}
		}

		cout << result << "\n";
	}

	return 0;
}