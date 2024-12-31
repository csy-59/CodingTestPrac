#include <stdio.h>
#include <vector>

using namespace std;
int main()
{
	vector<int> c;
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
	{
		int num;
		scanf("%d", &num);
		c.push_back(num);
	}

	int answer = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (k >= c[i])
		{
			int count = k / c[i];
			answer += count;
			k -= c[i] * count;
		}
	}

	printf("%d", answer);

	return 0;
}