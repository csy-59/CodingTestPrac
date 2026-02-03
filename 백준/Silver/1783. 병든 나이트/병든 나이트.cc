#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    if (n == 1)
    {
        cout << 1;
    }
    else if (n == 2)
    {
        cout << min((long long)4, (m + 1) / 2);
    }
    else 
    {

        cout << (m <= 6 ? min((long long)4, m) : m - 2);
    }

	return 0;
}