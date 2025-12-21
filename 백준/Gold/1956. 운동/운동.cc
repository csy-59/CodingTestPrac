#include <iostream>
#include <vector>

using namespace std;

const int MAX = 4000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int v, e;
	cin >> v >> e;

	vector<vector<int>> dist(v, vector<int>(v, MAX));

	for (int i = 0; i < v; ++i)
		dist[i][i] = 0;

	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		dist[a - 1][b - 1] = c;
	}

	for (int k = 0; k < v; ++k)
	{
		for (int i = 0; i < v; ++i)
		{
			if (dist[i][k] >= MAX)
				continue;

			for (int j = 0; j < v; ++j)
			{
				if (dist[k][j] >= MAX)
					continue;

				int newDist = dist[i][k] + dist[k][j];
				if (newDist < dist[i][j]) dist[i][j] = newDist;
			}
		}
	}

	int answer = MAX * 2;
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			if (i == j) continue;
			if (dist[i][j] == MAX || dist[j][i] == MAX) continue;

			answer = answer < dist[i][j] + dist[j][i] ? 
				answer : dist[i][j] + dist[j][i];
		}
	}

	if (answer >= MAX * 2) answer = -1;

	cout << answer;

	return 0;
}