#include <iostream>
#include <unordered_map>

using namespace std;

int const bingoCount = 5;
int bingoCheck[bingoCount + bingoCount + 2];
unordered_map<int, pair<int, int>> pos;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < bingoCount; ++i)
	{
		for (int j = 0; j < bingoCount; ++j)
		{
			int num;
			cin >> num;
			pos[num] = make_pair(i, j);
		}
	}

	int result = 0;
	int count = 0;
	for (int i = 0; i < bingoCount; ++i)
	{
		for (int j = 0; j < bingoCount; ++j)
		{
			int num;
			cin >> num;
			auto p = pos[num];

			++result;
			if (++bingoCheck[p.first] == bingoCount) ++count;
			if (++bingoCheck[p.second + bingoCount] == bingoCount) ++count;
			if ((p.first == p.second) && ++bingoCheck[bingoCount * 2] == bingoCount) ++count;
			if ((p.first + p.second == bingoCount - 1) && ++bingoCheck[bingoCount * 2 + 1] == bingoCount) ++count;

			if (count >= 3)
			{
				cout << result;
				return 0;
			}
		}
	}

	return 0;
}