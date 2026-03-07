#include <iostream>
#include <queue>

using namespace std;

int dir[4][2] = {
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};
bool isVisited[600][600] = { false };
string map[600];
int h, w;

int FindFriend(pair<int, int> s)
{
	queue<pair<int, int>> q;
	q.push(s);
	isVisited[s.first][s.second] = true;

	int count = 0;
	while (q.empty() == false)
	{
		auto p = q.front(); q.pop();

		if (map[p.first][p.second] == 'P')
			++count;

		for (int i = 0; i < 4; ++i)
		{
			auto np = make_pair<int, int>(p.first + dir[i][0], p.second + dir[i][1]);

			if (np.first < 0 || np.first >= h ||
				np.second < 0 || np.second >= w ||
				isVisited[np.first][np.second] == true ||
				map[np.first][np.second] == 'X')
				continue;

			isVisited[np.first][np.second] = true;
			q.push(np);
		}
	}

	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w;

	pair<int, int> start;
	for (int i = 0; i < h; ++i)
	{
		cin >> map[i];
		for (int j = 0; j < w; ++j)
		{
			if (map[i][j] == 'I')
				start = make_pair(i, j);
		}
	}

	int result = FindFriend(start);

	if (result == 0)
	{
		cout << "TT";
		return 0;
	}

	cout << result;

	return 0;
}