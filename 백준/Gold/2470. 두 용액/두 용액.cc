#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long v[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);

    int left = 0;
    int right = n - 1;

    long long best = llabs(v[left] + v[right]);
    long long ans1 = v[left], ans2 = v[right];

    while (left < right)
    {
        long long sum = v[left] + v[right];
        long long cur = llabs(sum);

        if (cur < best)
        {
            best = cur;
            ans1 = v[left];
            ans2 = v[right];
        }

        if (sum < 0)
            ++left;
        else
            --right;
    }

    cout << ans1 << " " << ans2;
    return 0;
}