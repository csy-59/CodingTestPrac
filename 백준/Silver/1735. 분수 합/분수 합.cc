#include <stdio.h>

int GetGCD(int a, int b)
{
	int max = a > b ? a : b;
	int min = a < b ? a : b;

	if (max % min == 0) return min;

	for (int i = min / 2; i >= 2; --i)
	{
		if (max % i == 0 && min % i == 0)
			return i;
	}

	return 1;
}

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	int denoGCD = GetGCD(b, d);
	int mole = a * d / denoGCD + c * b / denoGCD;

	int resultGCD = GetGCD(b * d / denoGCD, mole);
	printf("%d %d", mole / resultGCD, b * d / denoGCD / resultGCD);

	return 0;
}