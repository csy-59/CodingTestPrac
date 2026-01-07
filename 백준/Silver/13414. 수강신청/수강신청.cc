#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, l;
    cin >> k >> l;

    stack<string> nums;

    for (int i = 0; i < l; ++i)
    {
        string num;
        cin >> num;
        nums.push(num);
    }

    unordered_set<string> reserved;
    stack<string> result;
    while (nums.empty() == false)
    {
        string n = nums.top();
        nums.pop();

        if (reserved.find(n) != reserved.end())
            continue;

        reserved.insert(n);
        result.push(n);
    }

    for (int i = 0, size = result.size() >= k ? k : result.size(); i < size; ++i)
    {
        cout << result.top() << "\n";
        result.pop();
    }

	return 0;
}