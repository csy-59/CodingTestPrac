#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Number {
    int num;
    int time;
    int count;

    Number()
    {
        num = -1;
        time = count = 0;
    }

    Number(int num) : num(num)
    {
        time = count = 0;
    }

    Number(int num, int time) :num(num), time(time)
    {
        count = 1;
    }

    bool static cmpByRecommand(const Number a, const Number b)
    {
        if (a.count != b.count) return a.count > b.count;
        return a.time < b.time;
    }

    void Set(int num, int recommand, int time)
    {
        this->num = num;
        this->count = recommand;
        this->time = time;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    unordered_map<int, int> map;
    vector<Number> nums;

    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;

        if (map.find(num) != map.end())
        {
            ++nums[map[num]].count;
            continue;
        }

        nums.push_back(Number(num, i));
        map[num] = nums.size() - 1;
    }

    sort(nums.begin(), nums.end(), Number::cmpByRecommand);

    for (auto iter = nums.begin(); iter != nums.end(); ++iter)
    {
        for (int i = 0; i < iter->count; ++i)
        {
            cout << iter->num << " ";
        }
    }

    return 0;
}