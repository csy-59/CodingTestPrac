#include <iostream>
#include <vector>

using namespace std;

int INF = 100'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(i == j)
				map[i][j] = 0;

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		map[a][b] = min(map[a][b], c);
	}

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << (map[i][j] == INF ? 0 : map[i][j]) << " ";
		}
		cout << "\n";
	}

	return 0;
}