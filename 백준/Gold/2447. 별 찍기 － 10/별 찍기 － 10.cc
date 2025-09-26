#include <stdio.h>

char star[2188][2188] = { '\0' };
int N;

void solution(int n, int x, int y)
{
	if (n == 1)
	{
		star[x][y] = '*';
		return;
	}

	int newN = n / 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 1 && j == 1)
				continue;

			solution(newN, x + newN * i, y + newN * j);
		}
	}
}

int main()
{
	scanf("%d", &N);
	solution(N, 0, 0);
	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			if (star[i][j] == '\0')
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}