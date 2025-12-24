#include <iostream>
#include <math.h>

using namespace std;

long long FX[1000001] = { 0, };
long long GX[1000001] = { 0, };

void GetGX(int n)
{
    int sqrtNum = (int)sqrt(n);
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i)
        {
            FX[j] += i;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        GX[i] = GX[i - 1] + FX[i];
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    GetGX(1000000);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cout << GX[x] << "\n";
    }
}