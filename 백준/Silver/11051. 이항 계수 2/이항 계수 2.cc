#include <stdio.h>

int binomial[1001][1001];
int binomialDivedBy10007(int n, int k)
{
	if (k <= 0 || k >= n)
	{
		return 1;
	}

	if (binomial[n][k] != 0)
	{
		return binomial[n][k];
	}

	int result = binomialDivedBy10007(n - 1, k - 1) + binomialDivedBy10007(n - 1, k);
	binomial[n][k] = result;
	return (result > 20013) ? result % 10007 : result;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int result = binomialDivedBy10007(n, k) % 10007;

	printf("%d", result);

	return 0;
}