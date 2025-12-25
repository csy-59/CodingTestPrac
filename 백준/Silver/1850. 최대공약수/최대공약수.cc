#include <iostream>

using namespace std;

long long GCD(long long a, long long b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    long long n1, n2;
    cin >> n1 >> n2;

    long long a = min(n1, n2);
    long long b = max(n1, n2);

    long long result = 0;
    long long gcd = GCD(a, b);
    while (gcd-- > 0)
    {
        cout << 1;
    }

	return 0;
}