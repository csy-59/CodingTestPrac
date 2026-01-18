#include <bits/stdc++.h>
using namespace std;

int n, k;
int color[12][12];                 
vector<int> board[12][12];         
int x[10], y[10], dir[10];         

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int reverseDir(int d)
{
    if (d == 0) return 1;
    if (d == 1) return 0;
    if (d == 2) return 3;
    return 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> color[i][j];

    for (int i = 0; i < k; ++i)
    {
        cin >> x[i] >> y[i] >> dir[i];
        x[i]--; y[i]--; dir[i]--;
        board[x[i]][y[i]].push_back(i);
    }

    for (int turn = 1; turn <= 1000; ++turn)
    {
        for (int i = 0; i < k; ++i)
        {
            int cx = x[i], cy = y[i];
            int d = dir[i];

            auto &curStack = board[cx][cy];
            int idx = find(curStack.begin(), curStack.end(), i) - curStack.begin();

            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || color[nx][ny] == 2)
            {
                dir[i] = d = reverseDir(d);
                nx = cx + dx[d];
                ny = cy + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || color[nx][ny] == 2)
                    continue;
            }

            vector<int> moving(curStack.begin() + idx, curStack.end());
            curStack.erase(curStack.begin() + idx, curStack.end());

            if (color[nx][ny] == 1)
                reverse(moving.begin(), moving.end());

            for (int m : moving)
            {
                x[m] = nx;
                y[m] = ny;
                board[nx][ny].push_back(m);
            }

            if (board[nx][ny].size() >= 4)
            {
                cout << turn;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}
