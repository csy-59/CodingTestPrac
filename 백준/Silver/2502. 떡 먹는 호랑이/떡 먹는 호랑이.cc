#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, K;
    cin >> D >> K;

    int x[31] = { 0 }, y[31] = { 0 };
    x[1] = 1; y[1] = 0;
    x[2] = 0; y[2] = 1;

    for (int i = 3; i <= D; i++) {
        x[i] = x[i - 1] + x[i - 2];
        y[i] = y[i - 1] + y[i - 2];
    }

    int xd = x[D], yd = y[D];

    for (int i = 1; i <= K; i++) {
        int rem = K - yd * i;
        if (rem <= 0) continue;
        if (rem % xd != 0) continue;

        int j = rem / xd;
        if (1 <= j && j <= i) {
            cout << j << "\n" << i << "\n";
            return 0;
        }
    }
    return 0;
}
