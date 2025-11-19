#include <iostream>
#include <cstring>

using namespace std;

int n;
int price[2][100000] = { 0 };
int dp[100000][3];

int Solution(int num, int type)
{
	if (num >= n)
	{
		return 0;
	}

	if (type >= 0 && num >= 0 && dp[num][type] > -1)
	{
		return dp[num][type];
	}
	
	int max = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (type == i)
			continue;

		int value = Solution(num + 1, i);
		if (max < value)
			max = value;
	}

	int result = max + ((type == 0 || type == 1) && num >= 0 ? price[type][num] : 0);
	if (type >= 0 && num >= 0)
		dp[num][type] = result;

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t > 0)
	{
		--t;
		memset(dp, -1, sizeof(dp));

		cin >> n;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> price[i][j];
			}
		}

		cout << Solution(-1, -1) << "\n";
	}

	return 0;
}