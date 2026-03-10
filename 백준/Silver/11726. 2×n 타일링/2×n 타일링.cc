#include <iostream>

using namespace std;

int dp[1000] = { 0 };

int solution(int n)
{
	if (dp[n] != 0)
		return dp[n];

	if (n == 1)
	{
		dp[1] = 1;
		return 1;
	}

	if (n == 2)
	{
		dp[2] = 2;
		return 2;
	}

	dp[n] = (solution(n - 1) + solution(n - 2)) % 10007;
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	cout << solution(n);

	return 0;
}