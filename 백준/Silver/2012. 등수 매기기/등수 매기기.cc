#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; ++i)
	{
		cin >> v[i];
	}
	sort(v + 1, v + n + 1);

	long long result = 0;
	for (int i = 1; i <= n; ++i)
	{
		result += abs(v[i] - i);
	}

	cout << result;

	return 0;
}
