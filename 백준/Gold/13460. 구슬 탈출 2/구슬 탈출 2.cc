#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;
vector<string> v(10);
bool isVisited[10][10][10][10] = { false, };
pair<int, int> moveWay[4] = {
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(0, -1),
	make_pair(-1, 0)
};

pair<int, int> SetPosition(pair<int, int> p, pair<int, int> way, int& moveDir)
{
	moveDir = 0;
	while (true)
	{
		pair<int, int> newP = make_pair(p.first + way.first, p.second + way.second);
		if ((newP.first < 0 || newP.first >= n || newP.second < 0 || newP.second >= m)) return p;


		char t = v[newP.first][newP.second];
		if (t == '#') return p;
		if (t == 'O') return newP;

		p = newP;
		++moveDir;
	}
}

int solution(pair<int, int> r, pair<int, int> b, pair<int, int> e)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(r, b));
	isVisited[r.first][r.second][b.first][b.second] = true;

	int result = 0;
	while (q.empty() == false)
	{
		int size = q.size();
		++result;
		if (result > 10) return -1;

		while (size--)
		{
			pair<int, int> newR = q.front().first;
			pair<int, int> newB = q.front().second;
			q.pop();

			pair<int, int> nextR, nextB;
			int moveDistR, moveDistB;
			for (int i = 0; i < 4; ++i)
			{
				nextR = SetPosition(newR, moveWay[i], moveDistR);
				nextB = SetPosition(newB, moveWay[i], moveDistB);

				if ((nextB.first == e.first) && (nextB.second == e.second)) continue;
				if ((nextR.first == e.first) && (nextR.second == e.second)) return result;

				if (nextR.first == nextB.first && nextR.second == nextB.second)
				{
					if (moveDistR > moveDistB)
					{
						nextR.first -= moveWay[i].first;
						nextR.second -= moveWay[i].second;
					}
					else
					{
						nextB.first -= moveWay[i].first;
						nextB.second -= moveWay[i].second;
					}
				}


				if (isVisited[nextR.first][nextR.second][nextB.first][nextB.second] == true)
					continue;

				isVisited[nextR.first][nextR.second][nextB.first][nextB.second] = true;
				q.push(make_pair(nextR, nextB));
			}
		}
	}

	return -1;
}

int main()
{
	cin >> n >> m;

	pair<int, int> b, r, e;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 'B') b = make_pair(i, j);
			else if (v[i][j] == 'R') r = make_pair(i, j);
			else if (v[i][j] == 'O') e = make_pair(i, j);
		}
	}

	cout << solution(r, b, e);

	return 0;
}