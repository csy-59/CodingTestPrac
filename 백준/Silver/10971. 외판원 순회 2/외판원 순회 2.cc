#include <iostream>

using namespace std;

int n;
int map[10][10] = { 0 };

int result = 10000000;

void bt(int curIndex, int total, int startIndex, unsigned int isVisited)
{
    bool cannotReach = false;
    bool isAllVisited = true;
    for (int i = 0; i < n; ++i)
    {
        if ((isVisited & 1 << i) == (1 << i))
            continue;

        if (map[curIndex][i] == 0)
        {
            cannotReach = true;
            continue;
        }
            

        isAllVisited = false;
        bt(i, total + map[curIndex][i], startIndex, isVisited | 1 << i);
    }

    if (curIndex == startIndex && isAllVisited && cannotReach == false && result > total)
        result = total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        bt(i, 0, i, 0);
    }

    cout << result;

	return 0;
}