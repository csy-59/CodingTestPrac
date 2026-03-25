#include <iostream>
#include <vector>

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

        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        long long result = 0;
        int count = 0;
        int max = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (max > v[i])
            {
                ++count;
                result -= v[i];
            }
            else
            {
                result += count * max;
                count = 0;
                max = v[i];
            }
        }

        result += count * max;
        cout << result << "\n";
    }

	return 0;
}