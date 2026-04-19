#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int board[8][8];
int result = 64;

vector<pair<int, int>> cctv;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector<vector<vector<int>>> dir = {
    {},
    {{0},{1},{2},{3}},
    {{0,2},{1,3}},
    {{0,1},{1,2},{2,3},{3,0}},
    {{0,1,2},{1,2,3},{2,3,0},{3,0,1}},
    {{0,1,2,3}}
};

int selected[8];

void watch(int x, int y, int d, int temp[8][8])
{
    int nx = x + dx[d];
    int ny = y + dy[d];

    while (nx >= 0 && nx < n && ny >= 0 && ny < m && temp[nx][ny] != 6)
    {
        if (temp[nx][ny] == 0)
            temp[nx][ny] = -1;

        nx += dx[d];
        ny += dy[d];
    }
}

void bt(int idx)
{
    if (idx == cctv.size())
    {
        int temp[8][8];
        memcpy(temp, board, sizeof(board));

        for (int i = 0; i < cctv.size(); ++i)
        {
            int x = cctv[i].first;
            int y = cctv[i].second;
            int type = board[x][y];

            for (int j = 0; j < dir[type][selected[i]].size(); ++j)
            {
                int d = dir[type][selected[i]][j];
                watch(x, y, d, temp);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (temp[i][j] == 0)
                    cnt++;
            }
        }

        if (result > cnt)
            result = cnt;

        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int type = board[x][y];

    for (int i = 0; i < dir[type].size(); ++i)
    {
        selected[idx] = i;
        bt(idx + 1);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5)
                cctv.push_back(make_pair(i, j));
        }
    }

    bt(0);

    cout << result;
}