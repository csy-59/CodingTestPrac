#include <stdio.h>
#include <math.h>
#include <cstring>

int count[50001];

int result(int n)
{
	if (n <= 0)
		return 0;

	if (count[n] > 0)
		return count[n];

	int min = 5;
	int q = static_cast<int>(sqrt(n));
	int r = 1;
	for (int i = q; i >= 1; --i)
	{
		r = 1;
		r += result(n - i * i);
		if (r < min)
		{
			min = r;
		}
	}

	count[n] = min;
	return min;
}

int main()
{
	std::memset(count, -1, sizeof(count));
	count[1] = 1;
	count[2] = 2;
	count[3] = 3;
	count[4] = 1;

	int n;
	scanf("%d", &n);
	printf("%d", result(n));

	return 0;
}