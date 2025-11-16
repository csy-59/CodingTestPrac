#include <iostream>
#include <cstring>

using namespace std;

int n;
pair<int, int> timeTable[1500000];
int dp[1500000];

int MaxPrice(int d)
{
	if (d >= n)
		return 0;

	if (dp[d] > -1)
		return dp[d];

	int includeToday = (d + timeTable[d].first) > n ? 0 : timeTable[d].second + MaxPrice(d + timeTable[d].first);
	int excludeToday = MaxPrice(d + 1);

	dp[d] = max(includeToday, excludeToday);
	return dp[d];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int d, p;
		cin >> timeTable[i].first >> timeTable[i].second;
	}

	memset(dp, -1, sizeof(dp));
	cout << MaxPrice(0);

	return 0;
}