#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    long long n;
    cin >> n;

    long long result = n;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    cout << result << "\n";
    return 0;
}