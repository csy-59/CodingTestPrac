#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 19;
    int a[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> a[i][j];

    int dx[4] = { 0, 1, 1, -1 };
    int dy[4] = { 1, 0, 1, 1 };

    auto in = [&](int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
        };

    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (a[x][y] == 0) continue;
            int type = a[x][y];

            for (int dir = 0; dir < 4; ++dir) {
                int px = x - dx[dir];
                int py = y - dy[dir];

                if (in(px, py) && a[px][py] == type) continue;

                int cnt = 1;
                int nx = x, ny = y;
                while (true) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (!in(nx, ny) || a[nx][ny] != type) break;
                    cnt++;
                }

                if (cnt == 5) {
                    cout << type << "\n";
                    cout << x + 1 << " " << y + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}