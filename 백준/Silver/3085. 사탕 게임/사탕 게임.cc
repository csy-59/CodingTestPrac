#include <iostream>

using namespace std;

int n;
char map[50][50] = { '\0' };


int CheckRowMaxCount(int r)
{
    char pre = map[r][0];
    int count = 1;
    int maxCount = 0;

    for (int i = 1; i < n; ++i)
    {
        if (pre == map[r][i])
        {
            ++count;
            continue;
        }

        if (maxCount < count)
            maxCount = count;

        count = 1;
        pre = map[r][i];
    }

    return maxCount < count ? count : maxCount;
}

int CheckColumnMaxCount(int c)
{
    char pre = map[0][c];
    int count = 1;
    int maxCount = 0;

    for (int i = 1; i < n; ++i)
    {
        if (pre == map[i][c])
        {
            ++count;
            continue;
        }

        if (maxCount < count)
            maxCount = count;

        count = 1;
        pre = map[i][c];
    }

    return maxCount < count ? count : maxCount;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string r;
        cin >> r;
        for (int j = 0; j < n; ++j)
        {
            map[i][j] = r[j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        int t = CheckRowMaxCount(i);
        result = result < t ? t : result;
    }
    for (int i = 0; i < n; ++i)
    {
        int t = CheckColumnMaxCount(i);
        result = result < t ? t : result;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i - 1][j] == map[i][j])
                continue;

            int t = map[i - 1][j];
            map[i - 1][j] = map[i][j];
            map[i][j] = t;

            result = max(result, CheckRowMaxCount(i - 1));
            result = max(result, CheckRowMaxCount(i));
            result = max(result, CheckColumnMaxCount(j));

            t = map[i - 1][j];
            map[i - 1][j] = map[i][j];
            map[i][j] = t;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[j][i - 1] == map[j][i])
                continue;

            int t = map[j][i - 1];
            map[j][i - 1] = map[j][i];
            map[j][i] = t;

            result = max(result, CheckColumnMaxCount(i - 1));
            result = max(result, CheckColumnMaxCount(i));
            result = max(result, CheckRowMaxCount(j));
            
            t = map[j][i - 1];
            map[j][i - 1] = map[j][i];
            map[j][i] = t;
        }
    }

    cout << result;

	return 0;
}