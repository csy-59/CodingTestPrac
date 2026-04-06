#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> map(n, vector<char>(n, 0));
    pair<int, int> point(-1, -1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> map[i][j];

            if (point.first == -1 && map[i][j] == '*')
            {
                point.first = i + 1;
                point.second = j;
            }
        }
    }

    pair<int, int> heart(point);
    cout << heart.first + 1 << " " << heart.second + 1 << "\n";

    int waist = 0;
    int leftArm = 0, RightArm = 0;
    int leftLeg = 0, RightLeg = 0;

    // leftArm
    point.second -= 1;
    while (point.second >= 0 && map[point.first][point.second] == '*')
    {
        --point.second;
        ++leftArm;
    }
    cout << leftArm << " ";

    // rightArm
    point = heart; point.second += 1;
    while (point.second < n && map[point.first][point.second] == '*')
    {
        ++point.second;
        ++RightArm;
    }
    cout << RightArm << " ";

    // waist;
    point = heart; point.first += 1;
    while (point.first < n && map[point.first][point.second] == '*')
    {
        ++point.first;
        ++waist;
    }
    cout << waist << " ";

    while (point.first < n)
    {
        bool isThereLeg = false;
        if (point.second + 1 < n && map[point.first][point.second + 1] == '*')
        {
            ++RightLeg;
            isThereLeg = true;
        }

        if (point.second - 1 >= 0 && map[point.first][point.second - 1] == '*')
        {
            ++leftLeg;
            isThereLeg = true;
        }

        if (isThereLeg == false)
            break;

        ++point.first;
    }

    cout << leftLeg << " " << RightLeg;

	return 0;
}