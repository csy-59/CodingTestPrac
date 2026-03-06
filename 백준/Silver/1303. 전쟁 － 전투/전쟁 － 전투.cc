#include <iostream>
#include <queue>

using namespace std;

int dir[4][2] = {
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};
bool isVisited[100][100] = { false };
string map[100];
int h, w;

int power(pair<int, int> s)
{
	queue<pair<int, int>> q;
	q.push(s);
	isVisited[s.first][s.second] = true;

	char c = map[s.first][s.second];

	int count = 0;
	while (q.empty() == false)
	{
		auto p = q.front(); q.pop();
		++count;

		for (int i = 0; i < 4; ++i)
		{
			auto np = make_pair<int, int>(p.first + dir[i][0], p.second + dir[i][1]);

			if (np.first < 0 || np.first >= w ||
				np.second < 0 || np.second >= h ||
				isVisited[np.first][np.second] == true ||
				map[np.first][np.second] != c)
				continue;

			isVisited[np.first][np.second] = true;
			q.push(np);
		}
	}

	return count * count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w;

	for (int i = 0; i < w; ++i)
	{
		cin >> map[i];
	}

	int r1 = 0, r2 = 0;
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			if (isVisited[i][j] == true)
				continue;

			switch (map[i][j])
			{
			case 'W': r1 += power({ i,j }); break;
			case 'B': r2 += power({ i,j }); break;
			}
		}
	}

	cout << r1 << " " << r2;

	return 0;
}