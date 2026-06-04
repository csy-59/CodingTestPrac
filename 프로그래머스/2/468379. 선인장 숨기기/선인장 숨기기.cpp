#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    int maxDrop = drops.size();

    // rain[i][j] = 해당 칸에 처음 비가 오는 시간
    // 비가 끝까지 안 오면 maxDrop + 1
    vector<vector<int>> rain(m, vector<int>(n, maxDrop + 1));

    for (int i = 0; i < maxDrop; ++i) {
        int r = drops[i][0];
        int c = drops[i][1];

        // 같은 칸에 여러 번 비가 올 수 있으므로 처음 시간만 저장
        rain[r][c] = min(rain[r][c], i + 1);
    }

    // rowMin[i][j] = i행에서 j열부터 w칸의 최솟값
    vector<vector<int>> rowMin(m, vector<int>(n - w + 1));

    for (int i = 0; i < m; ++i) {
        deque<int> dq;

        for (int j = 0; j < n; ++j) {
            while (!dq.empty() && rain[i][dq.back()] >= rain[i][j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            if (!dq.empty() && dq.front() <= j - w) {
                dq.pop_front();
            }

            if (j >= w - 1) {
                rowMin[i][j - w + 1] = rain[i][dq.front()];
            }
        }
    }

    vector<int> answer = {0, 0};
    int bestRainTime = -1;

    // 각 열마다 세로 h칸 최솟값 계산
    for (int col = 0; col <= n - w; ++col) {
        deque<int> dq;

        for (int row = 0; row < m; ++row) {
            while (!dq.empty() && rowMin[dq.back()][col] >= rowMin[row][col]) {
                dq.pop_back();
            }

            dq.push_back(row);

            if (!dq.empty() && dq.front() <= row - h) {
                dq.pop_front();
            }

            if (row >= h - 1) {
                int top = row - h + 1;
                int left = col;

                // 이 h x w 영역 안에서 가장 빨리 비 오는 시간
                int rainTime = rowMin[dq.front()][col];

                if (rainTime > bestRainTime ||
                    (rainTime == bestRainTime &&
                     (top < answer[0] || (top == answer[0] && left < answer[1])))) {
                    bestRainTime = rainTime;
                    answer[0] = top;
                    answer[1] = left;
                }
            }
        }
    }

    return answer;
}