#include <iostream>
#include <vector>

using namespace std;

unsigned long long FindLow(vector<unsigned long long>& v, int endPos)
{
    unsigned long long min = v[0];
    int index = 0;
    for (int i = 0; i < endPos; ++i)
    {
        if (min > v[i])
        {
            min = v[i];
            index = i;
        }
    }

    return index;
}

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

    vector<unsigned long long> price(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> price[i];
    }

    unsigned long long result = 0;
    int l = FindLow(price, n - 1);
    int end = n - 2;
    while (l > 0)
    {
        unsigned long long dist = 0;
        for (int i = end; i >= l; --i)
        {
            dist += roads[i];
        }

        result += dist * price[l];

        end = l - 1;
        l = FindLow(price, l);
    }

    unsigned long long dist = 0;
    for (int i = end; i >= l; --i)
    {
        dist += roads[i];
    }

    result += dist * price[l];

    cout << result;

	return 0;
}