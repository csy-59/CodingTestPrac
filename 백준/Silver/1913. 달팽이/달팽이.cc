#include <iostream>
#include <vector>

using namespace std;

int way[4][2] =
{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size, n;
    cin >> size >> n;

    vector<vector<int>> map(size, vector<int>(size, 0));
    pair<int, int> nPos;
    pair<int, int> cur(size / 2, size / 2);
    int level = 0, num = 1, dir = 0, count = 1;

    while (num <= size * size)
    {
        if (n == num)
        {
            nPos = cur;
        }

        map[cur.first][cur.second] = num;
        ++num; --count;

        pair<int, int> newPos(cur.first + way[dir][0], cur.second + way[dir][1]);
        if (newPos.first > size / 2 + level || newPos.first < size / 2 - level ||
            newPos.second > size / 2 + level || newPos.second < size / 2 - level)
        {
            int tempDir = (dir + 1) % 4;
            newPos = make_pair(cur.first + way[tempDir][0], cur.second + way[tempDir][1]);

            if (count <= 0 || map[newPos.first][newPos.second] != 0)
            {
                ++level;
                tempDir = dir; count = (level + level + 1) * (level + level + 1) - num;
                newPos = make_pair(cur.first + way[dir][0], cur.second + way[dir][1]);
            }

            dir = tempDir;
        }

        cur = newPos;
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    cout << nPos.first + 1 << " " << nPos.second + 1;

	return 0;
}