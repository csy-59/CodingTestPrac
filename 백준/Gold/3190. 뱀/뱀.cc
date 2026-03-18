#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {
	0, 1,
	1, 0,
	0, -1,
	-1, 0
};
bool map[100][100] = { false };

bool isCrashSelf(vector<pair<int, int>> s, pair<int, int> pos)
{
	for (int i = 0, size = s.size(); i < size; ++i)
	{
		if (s[i] == pos)
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = true;
	}

	int l;
	cin >> l;

	vector<pair<int, int>> s;
	s.push_back({ 0,0 });

	bool isEnded = false;
	int time = 0;
	int curDir = 0;
	for (int i = 0; i < l; ++i)
	{
		int t;
		char d;
		cin >> t >> d;
		t = t - time;

		while (isEnded == false && t-- > 0)
		{
			++time;
			pair<int, int> nPos(s[0].first + dir[curDir][0], 
				s[0].second + dir[curDir][1]);

			if (nPos.first < 0 || nPos.first >= n ||
				nPos.second < 0 || nPos.second >= n ||
				isCrashSelf(s, nPos) == true)
			{
				isEnded = true;
				break;
			}

			bool isAdded = map[nPos.first][nPos.second];
			pair<int, int> addedPos = s[s.size() - 1];

			for (int j = s.size() -1; j > 0; --j)
			{
				s[j] = s[j - 1];
			}

			s[0] = nPos;

			if (isAdded)
			{
				map[nPos.first][nPos.second] = false;
				s.push_back(addedPos);
			}
		}

		switch (d)
		{
		case 'D': curDir = (curDir + 1) % 4; break;
		case 'L': curDir = (curDir + 3) % 4; break;
		}
	}

	if (isEnded)
	{
		cout << time;
		return 0;
	}

	while (true)
	{
		++time;
		pair<int, int> nPos(s[0].first + dir[curDir][0],
			s[0].second + dir[curDir][1]);

		if (nPos.first < 0 || nPos.first >= n ||
			nPos.second < 0 || nPos.second >= n ||
			isCrashSelf(s, nPos) == true)
		{
			cout << time;
			return 0;
		}

		bool isAdded = map[nPos.first][nPos.second];
		pair<int, int> addedPos = s[s.size() - 1];

		for (int j = s.size() - 1; j > 0; --j)
		{
			s[j] = s[j - 1];
		}

		s[0] = nPos;

		if (isAdded)
		{
			map[nPos.first][nPos.second] = false;
			s.push_back(addedPos);
		}
	}

	return 0;
}