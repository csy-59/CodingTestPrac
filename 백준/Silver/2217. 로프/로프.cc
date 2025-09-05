#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int c;
	scanf("%d", &c);

	vector<int> ropes(c);
	for (int i = 0; i < c; ++i)
	{
		scanf("%d", &ropes[i]);
	}

	sort(ropes.begin(), ropes.end(), less<int>());

	int max = -1;
	for (int i = 0; i < c; ++i)
	{
		if (ropes[i] * (c - i) < max)
            continue;

		max = ropes[i] * (c - i);
	}

	printf("%d", max);

	return 0;
}