#include <stdio.h>

long long int GetGCD(long long int a, long long int b)
{
	long long int max = a > b ? a : b;
	long long int min = a < b ? a : b;

	if (max % min == 0) return min;

	for (long long int i = min / 2; i >= 2 ; --i)
	{
		if (max % i == 0 && min % i == 0)
			return i;
	}

	return 1;
}

int main()
{
	long long int a, b;
	scanf("%lld %lld", &a, &b);

	long long int gcd = GetGCD(a, b);
	long long int result = a * b / gcd;
	printf("%lld", result);

	return 0;
}