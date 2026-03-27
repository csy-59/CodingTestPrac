#include <iostream>
#include <queue>

using namespace std;

int n, m;
bool isVisited[10001][10001] = {false};
bool isSmall[10001] = { false };

int solution()
{
    if (isSmall[2] == true)
        return -1;

    queue<pair<int,int>> q;
    q.push({ 2, 1 });

    isVisited[2][1] = true;

    int result = 1;
    int count = q.size();
    while (q.empty() == false)
    {
        if (count <= 0)
        {
            count = q.size();
            ++result;
        }

        pair<int, int> node = q.front(); q.pop();
        --count;
        if (node.first == n)
        {
            return result;
        }

        if (node.second + 1 < n && node.first + node.second + 1 <= n &&
            isSmall[node.first + node.second + 1] == false &&
            isVisited[node.first + node.second + 1][node.second + 1] == false)
        {
            isVisited[node.first + node.second + 1][node.second + 1] = true;
            q.push({ node.first + node.second + 1, node.second + 1 });
        }
        if (node.first + node.second <= n &&
            isSmall[node.first + node.second] == false &&
            isVisited[node.first + node.second][node.second] == false)
        {
            isVisited[node.first + node.second][node.second] = true;
            q.push({ node.first + node.second, node.second });
        }
        if (node.second - 1 > 0 && node.first + node.second - 1 <= n &&
            isSmall[node.first + node.second - 1] == false &&
            isVisited[node.first + node.second - 1][node.second - 1] == false)
        {
            isVisited[node.first + node.second - 1][node.second - 1] = true;
            q.push({ node.first + node.second - 1, node.second - 1 });
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;
        isSmall[num] = true;
    }

    cout << solution();

	return 0;
}