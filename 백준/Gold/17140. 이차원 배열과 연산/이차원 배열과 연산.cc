#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int width, height;
int board[101][101] = { 0, };
vector<pair<int, int>> temp;

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int GetIndex(int n)
{
	for (int i = 0, size = temp.size(); i < size; ++i)
	{
		if (temp[i].first == n)
			return i;
	}

	return -1;
}

void DoR()
{
	int newWidth = 0;
	for (int i = 0; i < height; ++i)
	{
		temp.clear();
		for (int j = 0; j < width; ++j)
		{
			if (board[i][j] == 0) continue;

			int index = GetIndex(board[i][j]);
			if (index == -1)
			{
				temp.push_back(make_pair(board[i][j], 1));
			}
			else
			{
				++temp[index].second;
			}
		}

		sort(temp.begin(), temp.end(), cmp);

		int j = 0;
		for (int t = 0, size = temp.size(); t < size; ++t)
		{
			if (j < 100) board[i][j++] = temp[t].first;
			if (j < 100) board[i][j++] = temp[t].second;
			if (j >= 100) break;
		}

		for (int t = j; t < width; ++t)
		{
			board[i][t] = 0;
		}

		if (newWidth < j)
		{
			newWidth = j;
		}
	}

	width = newWidth;
}

void DoC()
{
	int newHeight = 0;
	for (int i = 0; i < width; ++i)
	{
		temp.clear();
		for (int j = 0; j < height; ++j)
		{
			if (board[j][i] == 0) continue;

			int index = GetIndex(board[j][i]);
			if (index == -1)
			{
				temp.push_back(make_pair(board[j][i], 1));
			}
			else
			{
				++temp[index].second;
			}
		}

		sort(temp.begin(), temp.end(), cmp);

		int j = 0;
		for (int t = 0, size = temp.size(); t < size; ++t)
		{
			if (j < 100) board[j++][i] = temp[t].first;
			if (j < 100) board[j++][i] = temp[t].second;
			if (j >= 100) break;
		}

		for (int t = j; t < height; ++t)
		{
			board[t][i] = 0;
		}

		if (newHeight < j)
		{
			newHeight = j;
		}
	}

	height = newHeight;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c >> k;

	width = height = 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> board[i][j];
		}
	}

	int time = 0;
	while (board[r - 1][c - 1] != k)
	{
		if (time > 100)
		{
			cout << -1;
			return 0;
		}
		++time;

		if (height >= width) DoR();
		else DoC();
	}

	cout << time;

	return 0;
}