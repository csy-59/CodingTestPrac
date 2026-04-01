#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i)
    {
        dp[i] = dp[i + 1];

        if (i + v[i].first <= n)
        {
            dp[i] = max(dp[i], v[i].second + dp[i + v[i].first]);
        }
    }

    cout << dp[0];


	return 0;
}