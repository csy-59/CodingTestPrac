#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dir[4][2] = {
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

bool isVisited[251][251] = { false };
char map[251][251] = { '\0' };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;

	vector<pair<int, int>> points;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'v' ||
				map[i][j] == 'o')
			{
				points.push_back(make_pair(i, j));
			}
		}
	}

	int sheep = 0, wolve = 0;

	for (int i = 0, size = points.size(); i < size; ++i)
	{
		auto p = points[i];
		if (isVisited[p.first][p.second] == true)
		{
			continue;
		}

		int ts = 0, tw = 0;
		queue<pair<int, int>> q;
		q.push(p);
		isVisited[p.first][p.second] = true;

		while (q.empty() == false)
		{
			auto cp = q.front(); q.pop();

			switch (map[cp.first][cp.second])
			{
			case 'v': ++tw; break;
			case 'o': ++ts; break;
			}

			for (int j = 0; j < 4; ++j)
			{
				auto np = make_pair(cp.first + dir[j][0], cp.second + dir[j][1]);
				if (np.first < 0 || np.first >= h ||
					np.second < 0 || np.second >= w ||
					map[np.first][np.second] == '#' ||
					isVisited[np.first][np.second] == true)
				{
					continue;
				}

				isVisited[np.first][np.second] = true;
				q.push(np);
			}
		}

		if (ts > tw) sheep += ts;
		else wolve += tw;
	}

	cout << sheep << " " << wolve;

	return 0;
}