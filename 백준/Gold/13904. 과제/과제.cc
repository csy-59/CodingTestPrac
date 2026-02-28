#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using  namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first != b.first)
		return a.first < b.first;

	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i)
	{
		int s, d;
		cin >> s >> d;
		v[i].first = s;
		v[i].second = d;
	}

	sort(v.begin(), v.end(), cmp);

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; ++i)
	{
		q.push(v[i].second);
		if (q.size() > v[i].first)
		{
			q.pop();
		}
	}

	int result = 0;
	while (q.empty() == false)
	{
		result += q.top();
		q.pop();
	}

	cout << result << "\n";

	return 0;
}