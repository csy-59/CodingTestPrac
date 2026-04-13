#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<unsigned long long> roads(n - 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> roads[i];
    }

    vector<int> price(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> price[i];
    }

    unsigned long long result = 0;
    unsigned long long low = price[0];

    for (int i = 0; i < n - 1; ++i)
    {
        if (price[i] < low)
        {
            low = price[i];
        }

        result += low * roads[i];
    }

    cout << result;

	return 0;
}