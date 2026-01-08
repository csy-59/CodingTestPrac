#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pic {
    int num;
    int time;
    int recommand;

    Pic()
    {
        num = -1;
        time = recommand = 0;
    }

    Pic(int num): num(num)
    {
        time = recommand = 0;
    }

    bool static cmpByRecommand(const Pic a, const Pic b)
    {
        if (a.recommand != b.recommand) return a.recommand > b.recommand;
        return a.time > b.time;
    }

    bool static cmpByNum(const Pic a, const Pic b)
    {
        if (a.num == -1) return false;
        if (b.num == -1) return true;
        return a.num < b.num;
    }

    void Set(int num, int recommand, int time)
    {
        this->num = num;
        this->recommand = recommand;
        this->time = time;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Pic> pics(n);

    for (int i = 0; i < k; ++i)
    {
        int num;
        cin >> num;

        int index = 0; bool isClear = false;
        for (; index < n; ++index)
        {
            if (pics[index].num == -1) break;
            else if (pics[index].num == num)
            {
                ++pics[index].recommand;
                isClear = true;
                sort(pics.begin(), pics.end(), Pic::cmpByRecommand);
                break;
            }
        }

        if (isClear == true) continue;

        sort(pics.begin(), pics.end(), Pic::cmpByRecommand);
        index = index >= n ? n - 1 : index;
        pics[index].Set(num, 1, i);
    }

    sort(pics.begin(), pics.end(), Pic::cmpByNum);
    for (int i = 0; i < n; ++i)
    {
        if (pics[i].num == -1) break;
        cout << pics[i].num << " ";
    }

	return 0;
}