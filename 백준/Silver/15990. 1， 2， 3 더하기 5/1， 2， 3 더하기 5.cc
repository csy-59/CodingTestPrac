#include <iostream>
using namespace std;

const int MAX = 100000;
const int MOD = 1000000009;

long long dp[MAX + 1][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int n = 4; n <= MAX; ++n) {
        dp[n][1] = (dp[n - 1][2] + dp[n - 1][3]) % MOD;
        dp[n][2] = (dp[n - 2][1] + dp[n - 2][3]) % MOD;
        dp[n][3] = (dp[n - 3][1] + dp[n - 3][2]) % MOD;
    }

    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        long long ans = (dp[k][1] + dp[k][2] + dp[k][3]) % MOD;
        cout << ans << '\n';
    }
    return 0;
}
