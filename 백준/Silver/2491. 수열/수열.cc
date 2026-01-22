#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    int inc = 1;
    int dec = 1;
    int result = 1;

    for (int i = 1; i < N; i++) {
        if (v[i] >= v[i - 1]) {
            inc++;
        }
        else {
            inc = 1;
        }

        if (v[i] <= v[i - 1]) {
            dec++;
        }
        else {
            dec = 1;
        }

        result = max(result, max(inc, dec));
    }

    cout << result;
    return 0;
}
