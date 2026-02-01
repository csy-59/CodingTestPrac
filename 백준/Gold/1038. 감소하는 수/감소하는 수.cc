#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> nums;

void dfs(int prev, long long cur) {
    nums.push_back(cur);

    for (int next = prev - 1; next >= 0; next--) {
        dfs(next, cur * 10 + next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i <= 9; i++) {
        dfs(i, i);
    }

    sort(nums.begin(), nums.end());

    if (N >= nums.size())
        cout << -1;
    else
        cout << nums[N];

    return 0;
}
