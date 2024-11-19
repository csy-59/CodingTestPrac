#include <stdio.h>
#include <vector>
#include <unordered_set>

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);
}

int main()
{
	int count;
	scanf("%d", &count);

	std::vector<int> v;
	std::unordered_set<int> offsets;
	for (int i = 0; i < count; ++i)
	{
		int temp;
		scanf("%d", &temp);

		if (i > 0)
		{
			offsets.insert(temp - v[v.size() - 1]);
		}
		v.push_back(temp);
	}

	int a = 0, b = 0, offset = 1;
	for (auto iter = offsets.begin(); iter != offsets.end(); ++iter)
	{
		b = *iter;

		a = gcd(a, b);
	}

	printf("%d", (v[v.size() - 1] - v[0]) / a - count + 1);

	return 0;
}