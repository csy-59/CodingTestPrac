#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n, int count) {
    vector<vector<long long>> dp(n + 1, vector<long long>(count + 1, 0));

    dp[1][1] = 1;

    for (int h = 2; h <= n; ++h) {
        for (int c = 1; c <= count; ++c) {
            // h 높이 빌딩이 새롭게 보이는 경우
            dp[h][c] += dp[h - 1][c - 1];

            // h 높이 빌딩이 새롭게 보이지 않는 경우
            dp[h][c] += 2LL * (h - 1) * dp[h - 1][c];

            dp[h][c] %= MOD;
        }
    }

    return dp[n][count];
}