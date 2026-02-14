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

    bool isChanged = false;
    for (int i = n - 2; i >= 0; --i)
    {
        if (nums[i] <= nums[i + 1]) continue;

        isChanged = true;

        int j = n - 1;
        while (nums[j] >= nums[i]) j--;

        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        break;
    }

    if (isChanged == false)
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