#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

int dir[8][2]
{
	0, 1,
	0, -1,
	1, 0,
	-1, 0,
	1, 1,
	-1, -1,
	-1, 1,
	1, -1
};

int map[50][50] = { 0 };
bool isVisited[50][50] = { false };

int CountLand(int w, int h, vector<pair<int,int>> points)
{
	memset(isVisited, 0, sizeof(isVisited));

	int result = 0;
	for (int i = 0, size = points.size(); i < size; ++i)
	{
		if (isVisited[points[i].first][points[i].second] == true)
			continue;

		++result;

		stack<pair<int, int>> s;
		s.push(points[i]);

		while (s.empty() == false)
		{
			auto p = s.top();
			s.pop();

			isVisited[p.first][p.second] = true;

			for (int i = 0; i < 8; ++i)
			{
				auto nP = make_pair<int, int>(p.first + dir[i][0], p.second + dir[i][1]);
				if (nP.first < 0 || nP.first >= w || nP.second < 0 || nP.second >= h ||
					map[nP.first][nP.second] == 0 ||
					isVisited[nP.first][nP.second] == true)
					continue;

				s.push(nP);
			}
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int w, h;
	while (true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		vector<pair<int, int>> v;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> map[i][j];

				if(map[i][j] == 1)
					v.push_back({i, j});
			}
		}

		cout << CountLand(h, w, v) << "\n";
	}

	return 0;
}