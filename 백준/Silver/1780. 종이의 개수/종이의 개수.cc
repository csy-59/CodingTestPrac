#include <iostream>
using namespace std;

int n;
int map[3000][3000];
int counts[3] = { 0 };

void cutPaper(int r, int c, int size)
{
	int pre = map[r][c];
	for (int i = r; i < r + size; ++i)
	{
		for (int j = c; j < c + size; ++j)
		{
			if (pre != map[i][j])
			{
				for (int k = 0; k < 3; ++k)
				{
					int newr = r + k * (size / 3);

					for (int g = 0; g < 3; ++g)
					{
						int newc = c + g * (size / 3);

						cutPaper(newr, newc, size / 3);
					}
				}
				return;
			}
		}
	}
 	++counts[pre + 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	cutPaper(0, 0, n);

	for (int i = 0; i < 3; ++i)
	{
		cout << counts[i] << "\n";
	}

	return 0;
}