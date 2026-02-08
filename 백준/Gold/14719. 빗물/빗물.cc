#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<int> walls(w, 0);

    int result = 0;
    for (int i = 0; i < w; ++i)
    {
        cin >> walls[i];
    }

    for (int i = h; i >= 0; --i)
    {
        vector<int> pos;

        for (int j = 0; j < w; ++j)
        {
            if (walls[j] >= i)
                pos.push_back(j);
        }

        if (pos.size() <= 1)
            continue;

        for (int j = 0, size = pos.size(); j < size - 1; ++j)
        {
            result += pos[j + 1] - pos[j] - 1;
        }
    }

    cout << result;

	return 0;
}