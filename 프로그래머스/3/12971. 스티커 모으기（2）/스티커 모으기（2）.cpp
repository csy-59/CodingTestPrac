#include <vector>
#include <algorithm>

using namespace std;

int GetMax(const vector<int>& sticker, int start, int end)
{
    if (start > end) return 0;
    if (start == end) return sticker[start];

    int prev2 = sticker[start];
    int prev1 = max(sticker[start], sticker[start + 1]);

    for (int i = start + 2; i <= end; ++i)
    {
        int cur = max(prev1, prev2 + sticker[i]);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

int solution(vector<int> sticker)
{
    int n = sticker.size();

    if (n == 1)
        return sticker[0];

    if (n == 2)
        return max(sticker[0], sticker[1]);

    int includeFirst = GetMax(sticker, 0, n - 2);
    int excludeFirst = GetMax(sticker, 1, n - 1);

    return max(includeFirst, excludeFirst);
}