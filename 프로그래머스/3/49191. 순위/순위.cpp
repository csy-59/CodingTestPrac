#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

    // A가 B를 이겼다
    for (auto& r : results) {
        int winner = r[0];
        int loser = r[1];
        graph[winner][loser] = true;
    }

    // 플로이드-워셜
    // i -> k, k -> j 이면 i -> j
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

    // 각 선수의 순위를 알 수 있는지 확인
    for (int i = 1; i <= n; ++i) {
        int known = 0;

        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;

            // i가 j보다 높거나, j가 i보다 높으면 관계를 아는 것
            if (graph[i][j] || graph[j][i]) {
                ++known;
            }
        }

        if (known == n - 1) {
            ++answer;
        }
    }

    return answer;
}