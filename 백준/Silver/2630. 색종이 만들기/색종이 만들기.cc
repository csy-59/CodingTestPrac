#include <iostream>
using namespace std;

bool paper[128][128] = { false };
int counts[2] = { 0 };

void cutPaper(int r, int c, int size)
{
	bool pre = paper[r][c];

	for (int i = r; i < r + size; ++i)
	{
		for (int j = c; j < c + size; ++j)
		{
			if (pre != paper[i][j])
			{
				for (int k = 0; k < 2; ++k)
				{
					int newr = r + k * size / 2;
					for (int g = 0; g < 2; ++g)
					{
						int newc = c + g * size / 2;
						
						cutPaper(newr, newc, size / 2);
					}
				}

				return;
			}
		}
	}

	++counts[pre];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> paper[i][j];
		}
	}

	cutPaper(0, 0, n);

	for (int i = 0; i < 2; ++i)
	{
		cout << counts[i] << "\n";
	}

	return 0;
}