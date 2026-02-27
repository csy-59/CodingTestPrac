#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DIF_MAX = 100000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;
	while (k-- > 0)
	{
		int n;
		cin >> n;

		vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());
		
		int dif = abs(v[0] - v[1]);
		for (int i = 0; i < n - 2; ++i)
		{
			int newDif = abs(v[i] - v[(i + 2) % n]);
			if (dif < newDif)
				dif = newDif;
		}

		int newDif = abs(v[n - 1] - v[n - 2]);
		if (dif < newDif)
			dif = newDif;

		cout << dif << "\n";
	}

	return 0;
}