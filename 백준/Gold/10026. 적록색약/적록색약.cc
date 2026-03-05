#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n;
int dir[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

bool isVisited[201][201] = { false };
string map[200];

void CheckArea(char c, pair<int, int> startPoint)
{
	queue<pair<int, int>> q;
	q.push(startPoint); isVisited[startPoint.first][startPoint.second] = true;

	while (q.empty() == false)
	{
		auto p = q.front(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int,int> np = { p.first + dir[i][0], p.second + dir[i][1] };
			if (np.first < 0 || np.first >= n ||
				np.second < 0 || np.second >= n ||
				isVisited[np.first][np.second] == true ||
				map[np.first][np.second] != c)
				continue;

			isVisited[np.first][np.second] = true;
			q.push(np);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	vector<pair<int, int>> b;
	for (int i = 0; i < n; ++i)
	{
		cin >> map[i];
	}

	int r1 = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (isVisited[i][j] == true)
				continue;

 			++r1;
			CheckArea(map[i][j], { i,j });
		}
	}

	memset(isVisited, 0, sizeof(isVisited));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}

	int r2 = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (isVisited[i][j] == true)
				continue;

			++r2;
			CheckArea(map[i][j], { i,j });
		}
	}

	cout << r1 << " " << r2;

	return 0;
}