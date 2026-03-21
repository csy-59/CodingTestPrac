#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int m;
	cin >> m;

	int temp;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;

		cout << binary_search(arr, arr + n, temp) << "\n";
	}

	return 0;
}