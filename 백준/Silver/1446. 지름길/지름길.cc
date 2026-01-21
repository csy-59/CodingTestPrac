#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ShortCut {
    int start, end, length;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<ShortCut> shortcuts;
    for (int i = 0; i < n; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        if (e <= d && e - s > l) {
            shortcuts.push_back({ s, e, l });
        }
    }

    // start 기준 정렬
    sort(shortcuts.begin(), shortcuts.end(),
        [](const ShortCut& a, const ShortCut& b) {
            return a.start < b.start;
        });

    const int INF = 1e9;
    vector<int> dp(d + 1, INF);
    dp[0] = 0;

    int idx = 0;
    for (int i = 0; i < d; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);

        while (idx < shortcuts.size() && shortcuts[idx].start == i) {
            auto& sc = shortcuts[idx];
            dp[sc.end] = min(dp[sc.end], dp[i] + sc.length);
            idx++;
        }
    }

    cout << dp[d];
    return 0;
}
