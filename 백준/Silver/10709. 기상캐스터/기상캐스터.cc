#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;

	vector<vector<int>> map(h, vector<int>(w, -1));
	queue<pair<int, int>> clouds;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			char cloud;
			cin >> cloud;
			if (cloud == 'c') clouds.push(make_pair(i, j));
		}
	}

	while (clouds.empty() == false)
	{
		pair<int, int> c1 = clouds.front(); clouds.pop();
		pair<int, int> c2(c1.first, w);
		if (clouds.empty() == false && clouds.front().first == c1.first) c2 = clouds.front();

		for (int i = c1.second, t = 0; i < c2.second; ++i, ++t)
		{
			map[c1.first][i] = t;
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}