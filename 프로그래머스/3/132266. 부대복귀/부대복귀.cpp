#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<vector<int>> graph(n + 1);

    for (auto& road : roads) {
        int a = road[0];
        int b = road[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[destination] = 0;
    q.push(destination);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (dist[next] != -1)
                continue;

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    for (int source : sources) {
        answer.push_back(dist[source]);
    }

    return answer;
}