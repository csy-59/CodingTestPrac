#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> check[] = {
	make_pair(1, 0),
	make_pair(-1, 0),
	make_pair(0, 1),
	make_pair(0, -1),
};

int n, m;

void SetOutlineAir(vector<vector<int>>& v)
{
	bool isVisited[100][100] = { false, };

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	isVisited[0][0] = true;

	while (q.empty() == false)
	{
		auto p = q.front();
		q.pop();

		v[p.first][p.second] = 0;

		for (int i = 0; i < 4; ++i)
		{
			auto newP = make_pair(p.first + check[i].first, p.second + check[i].second);
			if (newP.first < 0 || newP.first >= n ||
				newP.second < 0 || newP.second >= m)
				continue;

			if (isVisited[newP.first][newP.second] == true)
				continue;

			if (v[newP.first][newP.second] == 0 || 
				v[newP.first][newP.second] == 1)
			{
				q.push(newP);
				isVisited[newP.first][newP.second] = true;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	queue<pair<int, int>> q;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = vector<int>(m);
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &v[i][j]);
			if (++v[i][j] == 2) q.push(make_pair(i, j));
		}
	}

	
	int result = 1;
	int size = q.size();
	queue<pair<int, int>> change;
	
	v[0][0] = 0;
	SetOutlineAir(v);

	while (q.empty() == false)
	{
		if (size <= 0)
		{
			size = q.size();
			++result;

			while (change.empty() == false)
			{
				v[change.front().first][change.front().second] = 0;
				change.pop();
			}

			SetOutlineAir(v);
		}

		pair<int, int> p = q.front();
		q.pop(); --size;

		int expos = 0;
		for (int i = 0; i < 4; ++i)
		{
			auto newPoint = make_pair(p.first + check[i].first, p.second + check[i].second);
			if (newPoint.first < 0 || newPoint.first >= n ||
				newPoint.second < 0 || newPoint.second >= m)
				continue;

			if (v[newPoint.first][newPoint.second] == 0)
			{
				if (++expos >= 2)
					break;
			}
		}

		if (expos < 2)
		{
			q.push(p);
			continue;
		}

		change.push(p);
	}

	printf("%d", result);

	return 0;
}