#include <stdio.h>

int field[51][51] = { 0 };
int result = 0;
int wid, hei, cabages;

void dfs(int r, int c)
{
	if (field[r][c] == 0)
	{
		return;
	}

	//자신 0으로 변경
	field[r][c] = 0;

	//오른쪽 탐색
	if (c > 0 && field[r][c - 1] == 1)
	{
		dfs(r, c - 1);
	}

	//아래쪽 탐색
	if (r < hei - 1 && field[r + 1][c] == 1)
	{
		dfs(r + 1, c);
	}

	//왼쪽 탐색
	if (c < wid - 1 && field[r][c + 1] == 1)
	{
		dfs(r, c + 1);
	}

	//위쪽 탐색
	if (r > 0 && field[r - 1][c] == 1)
	{
		dfs(r - 1, c);
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d %d", &wid, &hei, &cabages);

		int w, h;
		for (int i = 0; i < cabages; ++i)
		{
			scanf("%d %d", &w, &h);
			
			field[h][w] = 1;
		}

		for (int i = 0; i < hei; ++i)
		{
			for (int j = 0; j < wid; ++j)
			{
				if (field[i][j] == 1)
				{
					++result;
					dfs(i, j);
				}
			}
		}

		printf("%d\n", result);

		result = 0;
	}

	return 0;
}