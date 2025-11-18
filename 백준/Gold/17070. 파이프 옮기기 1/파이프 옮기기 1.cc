#include <iostream>
#include <cstring>

using namespace std;

int mapSize;
int map[17][17] = { 0 };
int dp[17][17][3];

bool IsArrived(int x, int y, int type)
{
	switch (type)
	{
	case 0: return (x == mapSize && (y + 1) == mapSize);
	case 1: return ((x + 1) == mapSize && y == mapSize);
	case 2: return ((x + 1) == mapSize && (y + 1) == mapSize);
	default: break;
	}

	return false;
}

bool CanMove(int x, int y, int type, int nextType)
{
	if (type == 0 && nextType == 1 ||
		type == 1 && nextType == 0)
		return false;

	int lastX = (type == 1 || type == 2) ? x + 1 : x;
	int lastY = (type == 0 || type == 2) ? y + 1 : y;

	switch (nextType)
	{
	case 0: return (lastY + 1) <= mapSize && map[lastX][lastY + 1] != 1;
	case 1: return (lastX + 1) <= mapSize && map[lastX + 1][lastY] != 1;
	case 2: return (lastY + 1) <= mapSize && (lastX + 1) <= mapSize && 
		map[lastX][lastY + 1] != 1 &&
		map[lastX + 1][lastY] != 1 && 
		map[lastX + 1][lastY + 1] != 1;
	default: break;
	}

	return false;
}

int Solution(int x, int y, int type)
{
	if (x > mapSize || y > mapSize)
	{
		return 0;
	}

	if (IsArrived(x, y, type) == true)
	{
		dp[x][y][type] = 1;
		return 1;
	}

	if (dp[x][y][type] >= 0)
	{
		return dp[x][y][type];
	}

	int lastX = (type == 1 || type == 2) ? x + 1 : x;
	int lastY = (type == 0 || type == 2) ? y + 1 : y;

	int result = 0;
	if (CanMove(x, y, type, 0) == true)
		result += Solution(lastX, lastY, 0);
	if (CanMove(x, y, type, 1) == true)
		result += Solution(lastX, lastY, 1);
	if (CanMove(x, y, type, 2) == true)
		result += Solution(lastX, lastY, 2);

	dp[x][y][type] = result;
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> mapSize;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			cin >> map[i + 1][j + 1];
		}
	}

 	cout << Solution(1, 1, 0);

	return 0;
}