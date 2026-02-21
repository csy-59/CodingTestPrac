#include <iostream>
#include <vector>

using namespace std;

int INF = INT16_MAX;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> map(n, vector<int>(n, INF));
    for (int i = 0; i < k; ++i)
    {
        int s, e;
        cin >> s >> e;
        map[s - 1][e - 1] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        map[i][i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int s = 0; s < n; ++s)
        {
            for (int e = 0; e < n; ++e)
            {
                map[s][e] = min(map[s][e], map[s][i] + map[i][e]);
            }
        }
    }

    int s; cin >> s;
    for (int i = 0; i < s; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        --node1; --node2;

        if (map[node1][node2] < INF)
            cout << "-1\n";
        else if (map[node2][node1] < INF)
            cout << "1\n";
        else
            cout << "0\n";
    }

	return 0;
}