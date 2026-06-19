#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    sort(money.begin(), money.end());

    for(int coin : money)
    {
        for(int value = coin; value <= n; ++value)
        {
            dp[value] = (dp[value] + dp[value - coin]) % MOD;
        }
    }

    return dp[n];
}