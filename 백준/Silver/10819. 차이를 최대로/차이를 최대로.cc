#include <iostream>
#include <vector>

using namespace std;

int N;
int result = 0;

void GetMax(int n, vector<int>& nums, int sum, int lastNum, int isVisited)
{
    if (n == N)
    {
        if (result < sum) result = sum;
        return;
    }

    if (n == 0)
    {
        for (int i = 0; i < N; ++i)
        {
            GetMax(1, nums, 0, nums[i], (isVisited | 1 << i));
        }
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        int checkSum = (1 << i);
        if ((isVisited & checkSum) == checkSum)
            continue;

        GetMax(n + 1, nums, sum + abs(lastNum - nums[i]), nums[i], (isVisited | checkSum));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> nums(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    GetMax(0, nums, 0, 0, 0);

    cout << result;

	return 0;
}