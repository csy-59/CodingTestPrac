#include <stdio.h>
#include <vector>

using namespace std;

struct UnionFindSet {
public:
	vector<int> p;

	UnionFindSet(int size) : p(size, -1) {}

	int FindRoot(int value)
	{
		if (p[value] < 0) return value;
		return p[value] = FindRoot(p[value]);
	}

	void Merge(int l, int r)
	{
		if (l < r) swap(l, r);

		int a = FindRoot(l);
		int b = FindRoot(r);
		if (a != b) p[b] = a;
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	UnionFindSet ufs = UnionFindSet(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);

		if (t == 0)
			ufs.Merge(a, b);
		else
			printf("%s\n", ufs.FindRoot(a) == ufs.FindRoot(b) ?
				"YES" : "NO");
	}

	return 0;
}