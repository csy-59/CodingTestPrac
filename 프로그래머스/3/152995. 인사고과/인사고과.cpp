#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[0] == b[0])
        return a[1] < b[1];

    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    int wanhoA = scores[0][0];
    int wanhoB = scores[0][1];
    int wanhoSum = wanhoA + wanhoB;

    sort(scores.begin(), scores.end(), cmp);

    int maxB = 0;
    int rank = 1;

    for(auto& score : scores)
    {
        int a = score[0];
        int b = score[1];
        int sum = a + b;

        // 앞에 있는 사람들은 a가 현재보다 크거나 같음.
        // 그런데 b까지 maxB보다 작으면, 둘 다 더 큰 사람이 존재한다는 뜻.
        if(b < maxB)
        {
            if(a == wanhoA && b == wanhoB)
                return -1;

            continue;
        }

        // 탈락하지 않은 사람 중 완호보다 합산 점수가 높으면 등수 밀림
        if(sum > wanhoSum)
            ++rank;

        maxB = max(maxB, b);
    }

    return rank;
}