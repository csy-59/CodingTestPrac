#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int result = 0;
    for (int i = 0, size = s.length(); i < size; ++i)
    {
        if (s[i] != 'P')
            continue;

        for (int j = max(0, i - k); j <= min(n - 1, i + k); ++j)
        {
            if (s[j] == 'H')
            {
                ++result;
                s[j] = ' ';
                break;
            }
        }
    }

    cout << result;

	return 0;
}