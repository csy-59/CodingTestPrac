#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int c;

void GetArray(vector<int>& v)
{
	int num;
	for (int i = 0; i < c; ++i)
	{
		scanf("%d", &v[i]);
	}
}

int main()
{
	scanf("%d", &c);

	vector<int> a(c);
	vector<int> b(c);

	GetArray(a);
	GetArray(b);

	sort(a.begin(), a.end(), less<int>());
	sort(b.begin(), b.end(), greater<int>());

	int result = 0;
	for (int i = 0; i < c; ++i)
	{
		result += a[i] * b[i];
	}

	printf("%d", result);

	return 0;
}