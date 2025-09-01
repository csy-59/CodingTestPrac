#include <stdio.h>

int count = 0;

int solution(int n, int c)
{
	if (n < 3)
		return -1;

	if (n == 3 || n == 5)
		return c + 1;

	int s = solution(n - 5, c + 1);
	if (s <= 0)
	{
		return solution(n - 3, c + 1);
	}

	return s;
}

int main()
{
	int n;
	scanf("%d", &n);

	count = n;
	printf("%d", solution(n, 0));

	return 0;
}