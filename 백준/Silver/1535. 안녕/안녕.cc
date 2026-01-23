#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> d(n), j(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    for (int i = 0; i < n; ++i) cin >> j[i];

    vector<int> dp(101, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int hp = 100; hp > d[i]; --hp)
        {
            dp[hp] = max(dp[hp], dp[hp - d[i]] + j[i]);
        }
    }

    cout << dp[100];
}
