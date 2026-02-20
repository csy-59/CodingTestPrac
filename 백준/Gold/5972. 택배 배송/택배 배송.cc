#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> map(n);

    for (int i = 0; i < m; ++i)
    {
        int s, e, v;
        cin >> s >> e >> v;
        --s; --e;

        map[s].push_back(make_pair(e, v));
        map[e].push_back(make_pair(s, v));
    }

    vector<int> dist(n, INT_MAX);

    // 최소 힙
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();

        int curDist = top.first;
        int node = top.second;

        if (curDist > dist[node])
            continue;

        for (int i = 0; i < map[node].size(); ++i)
        {
            int next = map[node][i].first;
            int weight = map[node][i].second;

            int newDist = curDist + weight;

            if (newDist < dist[next])
            {
                dist[next] = newDist;
                pq.push(make_pair(newDist, next));
            }
        }
    }

    cout << dist[n - 1];

    return 0;
}