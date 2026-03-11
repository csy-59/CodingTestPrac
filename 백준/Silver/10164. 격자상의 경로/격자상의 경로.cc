#include <iostream>

using namespace std;

int dp[16][16] = { 0 };

int Solution(int x, int y)
{
	if (dp[x][y] != 0)
		return dp[x][y];

	if (x == 0 || y == 0) {
		dp[x][y] = 1;
		return dp[x][y];
	}
		
	return Solution(x - 1, y) + Solution(x, y - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	int way = 1;
	pair<int, int> s(0, 0);
	if (k != 0)
	{
		s.first = k / m;
		s.second = k % m - 1;
		way = Solution(s.first, s.second);
	}

	s.first = n - s.first - 1;
	s.second = m - s.second - 1;
	cout << way * Solution(s.first, s.second);

	return 0;
}