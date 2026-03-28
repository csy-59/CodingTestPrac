#include <iostream>
#include <cstring>

using namespace std;

int coins[21];
int dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> coins[i];
        }

        int m;
        cin >> m;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = coins[i]; j <= m; ++j)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        cout << dp[m] << '\n';
    }

    return 0;
}