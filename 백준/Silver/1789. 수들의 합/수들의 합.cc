#include <stdio.h>

int main()
{
	long long n;
	scanf("%d", &n);

	long long num = n;
	long long result = 0;
	for (int i = 1; i <= n; ++i)
	{
		++result;
		if ((num - i) > i)
		{
			num -= i;
		}
		else
		{
			printf("%d", result);
			break;
		}
	}

	return 0;
}