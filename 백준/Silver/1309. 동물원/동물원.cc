#include <iostream>
#include <cstring>

using namespace std;

int dp[100000][3];

int solution(int n, int side)
{
	if (dp[n][side] > 0)
		return dp[n][side];

	int result = 0;
	if (side == 0)
	{
		result = (result + solution(n - 1, 0)) % 9901;
		result = (result + solution(n - 1, 1)) % 9901;
		result = (result + solution(n - 1, 2)) % 9901;
	}
	else if (side == 1)
	{
		result = (result + solution(n - 1, 0)) % 9901;
		result = (result + solution(n - 1, 2)) % 9901;
	}
	else
	{
		result = (result + solution(n - 1, 0)) % 9901;
		result = (result + solution(n - 1, 1)) % 9901;
	}

	dp[n][side] = result;
	return dp[n][side];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));
	dp[1][0] = 3;
	dp[1][1] = 2;
	dp[1][2] = 2;

	cout << solution(n, 0);

	return 0;
}