#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> m;

int result = 200;

void bt(int idx, int cnt, vector<int>& start)
{
    if (cnt == n / 2)
    {
        vector<bool> isStart(n, false);
        for (int x : start) isStart[x] = true;

        int sT = 0, sL = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j) continue;
                if (isStart[i] && isStart[j]) sT += m[i][j];
                if (!isStart[i] && !isStart[j]) sL += m[i][j];
            }
        }

        result = min(result, abs(sT - sL));
        return;
    }

    for (int i = idx; i < n; ++i)
    {
        start.push_back(i);
        bt(i + 1, cnt + 1, start);
        start.pop_back();
    }
}


int main()
{
    cin >> n;
    m.assign(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> m[i][j];

    vector<int> start;
    start.push_back(0);
    bt(1, 1, start);

    cout << result;
}