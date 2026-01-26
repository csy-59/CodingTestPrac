#include <iostream>
#include <vector>

using namespace std;
int n;

void Print(vector<int> nums)
{
    for (int i = 0, size = nums.size(); i < size; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

void backtracking(vector<int> nums, int isVisited)
{
    if (nums.size() == n)
    {
        Print(nums);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if ((isVisited & 1 << i) == (1 << i)) continue;
        vector<int> nN(nums); nN.push_back(i + 1);
        backtracking(nN, isVisited | 1 << i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    backtracking(vector<int>(0), 0);

	return 0;
}