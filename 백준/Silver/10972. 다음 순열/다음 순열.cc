#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    int pos = n - 1;
    for (int i = n - 2; i > -1; --i)
    {
        if (nums[i] > nums[i + 1])
            continue;

        pos = i;
        sort(nums.begin() + i + 1, nums.end());

        int dif = n; int t = pos;
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[j] > nums[pos] &&
                dif > nums[j] - nums[pos])
            {
                dif = nums[j] - nums[pos];
                t = j;
            }
        }

        int temp = nums[t];
        nums[t] = nums[pos];
        nums[pos] = temp;

        break;
    }

    if (pos == n - 1)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << nums[i] << " ";
    }

	return 0;
}