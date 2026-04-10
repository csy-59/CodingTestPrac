#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int i = 0;
    int result = 0, t = 0;
    bool isDifCol = false;
    while (i < n)
    {
        if (s[i] == 'B') isDifCol = true;
        else if (isDifCol) ++t;

        ++i;
    }

    result = t;

    isDifCol = false; t = 0; i = 0;
    while (i < n)
    {
        if (s[i] == 'R') isDifCol = true;
        else if (isDifCol) ++t;

        ++i;
    }

    result = min(t, result);

    isDifCol = false; t = 0; i = n - 1;
    while (i >= 0)
    {
        if (s[i] == 'B') isDifCol = true;
        else if (isDifCol) ++t;

        --i;
    }

    result = min(t, result);

    isDifCol = false; t = 0; i = n - 1;
    while (i >= 0)
    {
        if (s[i] == 'R') isDifCol = true;
        else if (isDifCol) ++t;

        --i;
    }

    result = min(t, result);

    cout << result;

	return 0;
}