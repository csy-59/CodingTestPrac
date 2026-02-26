#include <iostream>
#include <cstring>

using namespace std;

int n, k, result = -1;
int arr[500001] = { 0 };
int t[500001] = { 0 };

void merge(int s, int m, int e)
{
	int i = s, j = m + 1, index = 0;
	while (i <= m && j <= e)
	{
		if (arr[i] <= arr[j])
		{
			t[index++] = arr[i++];
		}
		else
		{
			t[index++] = arr[j++];
		}

		if (--k == 0)
		{
			result = t[index - 1];
		}
	}

	while (i <= m)
	{
		t[index++] = arr[i++];

		if (--k == 0)
		{
			result = t[index - 1];
		}
	}
	
	while (j <= e)
	{
		t[index++] = arr[j++];

		if (--k == 0)
		{
			result = t[index - 1];
		}
	}

	memcpy(arr + s, t, sizeof(int) * index);
}

void mergeSort(int s, int e)
{
	if (s >= e)
		return;

	int m = (s + e) / 2;
	mergeSort(s, m);
	mergeSort(m + 1, e);
	merge(s, m, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	mergeSort(0, n - 1);
	cout << result;

	return 0;
}