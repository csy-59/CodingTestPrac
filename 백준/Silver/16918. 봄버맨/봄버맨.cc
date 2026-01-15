#include <iostream>
#include <vector>

using namespace std;

void Print(vector<vector<int>>& map, int r, int c)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << ((map[i][j] > 0) ? "O" : ".");
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, c, n;
	cin >> r >> c >> n;

	vector<vector<int>> map(r, vector<int>(c, 0));

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			char t; cin >> t;

			if (t == 'O') map[i][j] = 2;
		}
	}

	bool timeToPlace = true;
	while (--n > 0)
	{
		if (timeToPlace)
		{
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
				{
					if (map[i][j] == 0) map[i][j] = 3;
				}
			}
		}
		else
		{
			vector<pair<int, int>> boom;

			for (int x = 0; x < r; ++x)
			{
				for (int y = 0; y < c; ++y)
				{
					if (map[x][y] > 1) 
					{
						map[x][y]--;
						if (map[x][y] == 1) boom.push_back({ x, y });
					}
				}
			}

			for (int t = 0; t < boom.size(); ++t)
			{
				int x = boom[t].first;
				int y = boom[t].second;

				map[x][y] = 0;
				if (x + 1 < r)	map[x + 1][y] = 0;
				if (x - 1 >= 0) map[x - 1][y] = 0;
				if (y + 1 < c)	map[x][y + 1] = 0;
				if (y - 1 >= 0) map[x][y - 1] = 0;
			}
		}
		timeToPlace = !timeToPlace;
	}

	Print(map, r, c);

	return 0;
}