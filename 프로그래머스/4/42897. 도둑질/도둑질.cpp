#include <string>
#include <vector>

using namespace std;

int Search(vector<int>& money, int start, int end)
{
    if (start == end)
        return money[start];

    int prev2 = money[start];
    int prev1 = max(money[start], money[start + 1]);

    for (int i = start + 2; i <= end; ++i)
    {
        int cur = max(prev1, prev2 + money[i]);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

int solution(vector<int> money) {
    int size = money.size();
    int answer = max(Search(money, 0, size - 2), Search(money, 1, size - 1));
    return answer;
}