#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int n;
int cardPrice[1000];
int dp[1000];

int Solution(int count)
{
	if (count <= 0)
		return 0;

	if (dp[count] > -1)
		return dp[count];

	int min = INT_MAX;
	for (int i = count; i > 0; --i)
	{
		int t = cardPrice[i - 1] + Solution(count - i);
		if (min > t)
			min = t;
	}

	dp[count] = min;
	return min;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> cardPrice[i];
	}

	cout << Solution(n);

 	return 0;
}