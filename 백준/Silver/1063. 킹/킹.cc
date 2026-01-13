#include <iostream>

using namespace std;

pair<int, int> moveDir[8]
{
	make_pair(1, 0),
	make_pair(-1, 0),
	make_pair(0, -1),
	make_pair(0, 1),
	make_pair(1, 1),
	make_pair(-1, 1),
	make_pair(1, -1),
	make_pair(-1, -1)
};

const int maxSize = 8;

pair<int, int> k(0, 0);
pair<int, int> s(0, 0);

pair<int, int> GetPos(string p)
{
	return make_pair(p[0] - 'A', p[1] - '1');
}

string GetPos(pair<int, int> p)
{
	string result = "AA";
	result[0] = 'A' + p.first;
	result[1] = '1' + p.second;
	return result;
}

void MoveKing(string way)
{
	int dir = 0;

	if (way.compare("R") == 0)			dir = 0;
	else if (way.compare("L") == 0)		dir = 1;
	else if (way.compare("B") == 0)		dir = 2;
	else if (way.compare("T") == 0)		dir = 3;
	else if (way.compare("RT") == 0)	dir = 4;
	else if (way.compare("LT") == 0)	dir = 5;
	else if (way.compare("RB") == 0)	dir = 6;
	else if (way.compare("LB") == 0)	dir = 7;
	else return;

	auto newK = make_pair(k.first + moveDir[dir].first, k.second + moveDir[dir].second);
	auto newS = (s != newK) ? s : make_pair(s.first + moveDir[dir].first, s.second + moveDir[dir].second);

	if (newK.first < 0 || newK.first >= maxSize ||
		newK.second < 0 || newK.second >= maxSize ||
		newS.first < 0 || newS.first >= maxSize ||
		newS.second < 0 || newS.second >= maxSize)
		return;

	k = newK;
	s = newS;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string king, stone;
	int n;
	cin >> king >> stone >> n;

	k = GetPos(king);
	s = GetPos(stone);

	for (int i = 0; i < n; ++i)
	{
		string way;
		cin >> way;

		MoveKing(way);
	}

	cout << GetPos(k) << "\n" << GetPos(s);

	return 0;
}