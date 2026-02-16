#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> f(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> f[i];
    }

    int result = 0;

    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;

        for (int j = 0; j < n; ++j)
        {
            if (i == j) 
                continue;

            if (f[i][j] == 'Y')
            {
                cnt++;
                continue;
            }

            for (int k = 0; k < n; ++k)
            {
                if (f[i][k] == 'Y' && f[k][j] == 'Y')
                {
                    cnt++;
                    break;
                }
            }
        }

        result = max(result, cnt);
    }

    cout << result;

	return 0;
}