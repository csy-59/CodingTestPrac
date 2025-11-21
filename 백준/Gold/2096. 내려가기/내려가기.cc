#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long maxPrev[3] = { 0,0,0 };
    long long minPrev[3] = { 0,0,0 };
    bool first = true;

    for (int i = 0; i < n; ++i) {
        int a0, a1, a2;
        cin >> a0 >> a1 >> a2;

        long long maxCur[3], minCur[3];
        if (first) {
            // 첫 행 초기화
            maxCur[0] = minCur[0] = a0;
            maxCur[1] = minCur[1] = a1;
            maxCur[2] = minCur[2] = a2;
            first = false;
        }
        else {
            // max 갱신
            maxCur[0] = max(maxPrev[0], maxPrev[1]) + a0;
            maxCur[1] = max({ maxPrev[0], maxPrev[1], maxPrev[2] }) + a1;
            maxCur[2] = max(maxPrev[1], maxPrev[2]) + a2;
            // min 갱신
            minCur[0] = min(minPrev[0], minPrev[1]) + a0;
            minCur[1] = min({ minPrev[0], minPrev[1], minPrev[2] }) + a1;
            minCur[2] = min(minPrev[1], minPrev[2]) + a2;
        }
        memcpy(maxPrev, maxCur, sizeof maxPrev);
        memcpy(minPrev, minCur, sizeof minPrev);
    }

    cout << max({ maxPrev[0], maxPrev[1], maxPrev[2] }) << " "
        << min({ minPrev[0], minPrev[1], minPrev[2] }) << "\n";
    return 0;
}
