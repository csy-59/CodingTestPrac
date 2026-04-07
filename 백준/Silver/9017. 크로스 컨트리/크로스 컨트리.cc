#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;

        vector<int> order(n);
        unordered_map<int, int> cnt;

        for (int i = 0; i < n; ++i)
        {
            cin >> order[i];
            cnt[order[i]]++;
        }

        unordered_map<int, vector<int>> score;
        int rank = 1;

        for (int i = 0; i < n; ++i)
        {
            int team = order[i];
            if (cnt[team] >= 6)
            {
                score[team].push_back(rank);
                rank++;
            }
        }

        int winner = -1;
        int bestSum = 1e9;
        int bestFifth = 1e9;

        for (auto& p : score)
        {
            int team = p.first;
            vector<int>& v = p.second;

            int sum4 = v[0] + v[1] + v[2] + v[3];
            int fifth = v[4];

            if (sum4 < bestSum)
            {
                bestSum = sum4;
                bestFifth = fifth;
                winner = team;
            }
            else if (sum4 == bestSum)
            {
                if (fifth < bestFifth)
                {
                    bestFifth = fifth;
                    winner = team;
                }
            }
        }

        cout << winner << '\n';
    }

    return 0;
}