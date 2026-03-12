#include <iostream>

using namespace std;

int price[1001] = { 0 };
int dp[1000] = { 0 };

int Solution(int n)
{
	if (n <= 0) return 0;
	if (dp[n] != 0) return dp[n];
	if (n == 1)
	{
		dp[n] = price[n];
		return dp[n];
	}

	dp[n] = price[n];
	for (int i = 1; i < n; ++i)
	{
		dp[n] = max(dp[n], Solution(i) + Solution(n - i));
	}

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> price[i + 1];
	}

	cout << Solution(n);

	return 0;
}