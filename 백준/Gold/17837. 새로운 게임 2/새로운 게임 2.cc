#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

pair<int, int> moveWay[4] = {
	make_pair(0, 1),
	make_pair(0, -1),
	make_pair(-1, 0),
	make_pair(1, 0)
};

class Piece;

int n;
int map[12][12] = { 0, };
Piece* PiecePos[12][12] = { nullptr };

class Piece {
public:
	int num;
	Piece* top;
	Piece* bottom;
	pair<int, int> pos;
	int dir;

	Piece()
	{
		pos = make_pair(0, 0);
		dir = -1;
		num = -1;
		top = bottom = nullptr;
	}

	void Set(int x, int y, int d, int Number)
	{
		pos.first = x - 1;
		pos.second = y - 1;
		dir = d - 1;
		num = Number;
	}

	int Move()
	{
		auto nPos = make_pair(pos.first + moveWay[dir].first, pos.second + moveWay[dir].second);
		bool isRed = false;

		// 파랑
		if (nPos.first < 0 || nPos.first >= n ||
			nPos.second < 0 || nPos.second >= n ||
			map[nPos.first][nPos.second] == 2)
		{
			Flip();

			auto nnPos = make_pair(pos.first + moveWay[dir].first, pos.second + moveWay[dir].second);
			bool cannotMove = nnPos.first < 0 || nnPos.first >= n ||
				nnPos.second < 0 || nnPos.second >= n ||
				map[nnPos.first][nnPos.second] == 2;

			if (cannotMove == true)
			{
				return PiecePos[pos.first][pos.second]->GetCurrentStack();
			}

			nPos = nnPos;
		}

		// 이동
		if (bottom == nullptr) PiecePos[pos.first][pos.second] = nullptr;
		else 
		{
			bottom->top = nullptr; bottom = nullptr;
		}

		pos = nPos;
		
		auto nBottom = PiecePos[pos.first][pos.second];
		if (nBottom == nullptr)
		{
			PiecePos[pos.first][pos.second] = this;
			if (bottom != nullptr) bottom->top = nullptr;
			bottom = nullptr;
		}
		else
		{
			bottom = nBottom->GetSuperTop();
			bottom->top = this;
		}

		if (top != nullptr) 
			top->Move(dir);
		
		if (map[pos.first][pos.second] == 1)
		{
			if (PiecePos[pos.first][pos.second] == this)
			{
				PiecePos[pos.first][pos.second] = GetSuperTop();
			}

			auto b = bottom; auto t = GetSuperTop(); bottom = nullptr;
			if (b != nullptr) b->top = nullptr;
			Reverse();
			if(b != nullptr) b->top = t;
			t->bottom = b;
		}

		return PiecePos[pos.first][pos.second]->GetCurrentStack();
	}

	void Move(int parentDir)
	{
		pos.first += moveWay[parentDir].first;
		pos.second += moveWay[parentDir].second;

		if (top != nullptr) top->Move(parentDir);
	}

	void Flip()
	{
		switch (dir)
		{
		case 0: dir = 1; break;
		case 1: dir = 0; break;
		case 2: dir = 3; break;
		case 3: dir = 2; break;
		}
	}

	void Reverse()
	{
		if (top != nullptr)
			top->Reverse();

		auto t = bottom;
		bottom = top;
		top = t;
	}

	Piece* GetSuperBottom()
	{
		return (bottom != nullptr) ? bottom->GetSuperBottom() : this;
	}

	Piece* GetSuperTop()
	{
		return (top != nullptr) ? top->GetSuperTop() : this;
	}

	int GetCurrentStack()
	{
		return GetSuperBottom()->GetStackSize();
	}

	int GetStackSize()
	{
		return top != nullptr ? top->GetStackSize() + 1 : 1;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	vector<Piece> pieces(k);
	for (int i = 0; i < k; ++i)
	{
		int x, y, d;
		cin >> x >> y >> d;
		pieces[i].Set(x, y, d, i + 1);
		PiecePos[x - 1][y - 1] = &pieces[i];
	}

	int time = 1;
	while (time <= 1000)
	{
		for (int i = 0; i < k; ++i)
		{
			if (pieces[i].Move() >= 4)
			{
				cout << time;
				return 0;
			}
		}
 		++time;
	}

	cout << -1;
	return 0;
}