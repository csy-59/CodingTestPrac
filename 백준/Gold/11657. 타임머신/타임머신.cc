#include <iostream>
#include <vector>

using namespace std;

long long INF = 1e9;

struct edge {
    int s;
    int e;
    int v;

    edge() : s(0), e(0), v(0) {}
    edge(int s, int e, int v) : s(s), e(e), v(v) {}
    void Set(int s, int e, int v)
    {
        this->s = s;
        this->e = e;
        this->v = v;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int s, e, v;
        cin >> s >> e >> v;
        --s; --e;
        edges[i].Set(s, e, v);
    }

    vector<long long> dist(n, INF);
    dist[0] = 0;

    bool isNegLoop = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dist[edges[j].s] == INF)
                continue;

            if (dist[edges[j].e] > dist[edges[j].s] + edges[j].v)
            {
                dist[edges[j].e] = dist[edges[j].s] + edges[j].v;
            }
        }
    }

    for (int j = 0; j < m; ++j)
    {
        if (dist[edges[j].s] == INF)
            continue;

        if (dist[edges[j].e] > dist[edges[j].s] + edges[j].v)
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if (dist[i] == INF)
        {
            cout << -1 << "\n";
            continue;
        }

        cout << dist[i] << "\n";
    }

	return 0;
}