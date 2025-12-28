#include <iostream>
#include <vector>
#include <algorithm>

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

	long long n, s;
	cin >> n >> s;

	vector<long long> a(n, 0);

	for (int i = 0; i < n; ++i)
	{
		long long num;
		cin >> num;

		a[i] = abs(num - s);
	}

	sort(a.begin(), a.end(), greater<long long>());

	int result = a[0];
	for (int i = 1; i < n; ++i)
	{
		result = GCD(result, a[i]);
	}

	cout << result;

	return 0;
}