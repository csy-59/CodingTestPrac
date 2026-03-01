#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second != b.second)
		return a.second > b.second;

	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, int> m;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string t;
		cin >> t;

		if (m.find(t) == m.end())
		{
			m[t] = 0;
		}

		++m[t];
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	cout << v[0].first;

	return 0;
}