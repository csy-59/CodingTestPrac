#include <iostream>
#include <cstring>

using namespace std;

int n;
int nums[100];
int result;

long long dp[100][21];

long long count(int pos, int total)
{
	if (dp[pos][total] >= 0)
	{
		return dp[pos][total];
	}

	long long c = 0;
	if (pos == n - 1)
	{
		c = total == result ? 1 : 0;
		dp[pos][total] = c;
		return c;
	}

	if (total + nums[pos] <= 20)
	{
		c += count(pos + 1, total + nums[pos]);
	}

	if (total - nums[pos] >= 0)
	{
		c += count(pos + 1, total - nums[pos]);
	}

	dp[pos][total] = c;
	return c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(nums, -1, sizeof(nums));
	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	result = nums[n - 1];

	cout << count(1, nums[0]);

	return 0;
}