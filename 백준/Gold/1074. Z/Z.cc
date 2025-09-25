#include <stdio.h>
#include <cmath>
using namespace std;

int n;
long r, c;

long long z(int num, long x, long y)
{
	int k = 0;
	k += (pow(2, num)/ 2 - 1 < y);
	k += ((pow(2, num) - 1) / 2 < x) * 2;
	
	if (num == 1)
	{
		return k;
	}

	return pow(2, (num - 1) * 2) * k + z(num - 1, x - k / 2 * pow(2, num - 1), y - k % 2 * pow(2, num - 1));
}

int main()
{
	scanf("%d %ld %ld", &n, &r, &c);
    printf("%lld", z(n, r, c));

	return 0;
}
