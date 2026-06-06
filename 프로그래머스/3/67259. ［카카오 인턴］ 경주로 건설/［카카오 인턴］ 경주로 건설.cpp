#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    int dir;
    int cost;
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.cost > b.cost;
    }
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int solution(vector<vector<int>> board) {
    int n = board.size();
    const int INF = 987654321;

    vector<vector<vector<int>>> dist(
        n, vector<vector<int>>(n, vector<int>(4, INF))
    );

    priority_queue<Node, vector<Node>, Compare> pq;

    for(int d = 0; d < 4; ++d) {
        dist[0][0][d] = 0;
    }

    pq.push({0, 0, -1, 0});

    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        for(int nd = 0; nd < 4; ++nd) {
            int nx = cur.x + dx[nd];
            int ny = cur.y + dy[nd];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if(board[nx][ny] == 1)
                continue;

            int nextCost = cur.cost + 100;

            if(cur.dir != -1 && cur.dir != nd) {
                nextCost += 500;
            }

            if(dist[nx][ny][nd] > nextCost) {
                dist[nx][ny][nd] = nextCost;
                pq.push({nx, ny, nd, nextCost});
            }
        }
    }

    return *min_element(dist[n - 1][n - 1].begin(), dist[n - 1][n - 1].end());
}