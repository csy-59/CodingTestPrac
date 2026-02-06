#include <iostream>
#include <vector>

using namespace std;

int width, height;
int GetMinDist(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return abs(a.second - b.second);
    }

    if (a.first > b.first)
    {
        pair<int, int> t = b;
        b = a; a = t;
    }

    if (a.first == 1)
    {
        switch (b.first)
        {
        case 2: return height + min(a.second + b.second, width - a.second + width - b.second);
        case 3: return a.second + b.second;
        case 4:return width - a.second + b.second;
        }
    }

    if (a.first == 2)
    {
        switch (b.first)
        {
        case 3: return a.second + height - b.second;
        case 4: return width - a.second + height - b.second;
        }
    }

    // a.first = 3 , b.first = 4
    return width + min(a.second + b.second, height - a.second + height - b.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> width >> height;

    int n;
    cin >> n;

    vector<pair<int, int>> pos;
    pos.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int s, num;
        cin >> s >> num;

        pos.push_back(make_pair(s, num));
    }

    pair<int, int> me;
    cin >> me.first >> me.second;

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        result += GetMinDist(pos[i], me);
    }

    cout << result;

	return 0;
}