#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

void FindAndPlus(unordered_map<int, int>& m, int key, int plusValue)
{
	if (m.find(key) == m.end())
	{
		m[key] = plusValue;
	}
	else
	{
		m[key] += plusValue;
	}

	if (m[key] <= 0)
	{
		m.erase(key);
	}
}

int main()
{
	int n, d, k, c;
	scanf("%d %d %d %d", &n, &d, &k, &c);

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
	}

	if (k == n)
	{
		printf("%d", n);
		return 0;
	}

	int max = 0;
	int start = 0, end = k;
	unordered_map<int, int> m;
	m.reserve(d);
	for (int i = start; i < end; ++i)
	{
		FindAndPlus(m, v[i], 1);
	}

	max = m.size() + (m.count(c) > 0 ? 0 : 1);

 	for (int i = 1; i < n; ++i)
	{
		FindAndPlus(m, v[start], -1);
		FindAndPlus(m, v[end], 1);

		end = (end + 1) % n;
		start = (start + 1) % n;

		int count = m.size() + (m.count(c) > 0 ? 0 : 1);
		if (max < count)
			max = count;
	}

	printf("%d", max);

	return 0;
}