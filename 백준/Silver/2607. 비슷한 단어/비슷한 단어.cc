#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    --n;

    string s1;
    cin >> s1;

    map<char, int> sM;
    for (int i = 0, size = s1.size(); i < size; ++i)
    {
        if (sM.find(s1[i]) == sM.end())
        {
            sM[s1[i]] = 1;
        }
        else
        {
            ++sM[s1[i]];
        }
    }

    int result = 0;
    while (n-- > 0)
    {
        string s;
        cin >> s;

        int dif = 0;
        int newN = 0;
        map<char, int> m = sM;
        for (int i = 0, size = s.size(); i < size; ++i)
        {
            if (m.find(s[i]) == m.end() || m[s[i]] == 0)
            {
                ++newN;
                continue;
            }

            --m[s[i]];
        }

        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if (abs(iter->second) >= 1)
            {
                dif += abs(iter->second);
            }
        }

        if ((dif == 1 && newN == 1) || (dif + newN <= 1))
        {
            ++result;
        }
    }

    cout << result;

	return 0;
}