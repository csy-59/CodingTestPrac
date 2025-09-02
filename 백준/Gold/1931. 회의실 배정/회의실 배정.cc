#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int c;
vector<pair<int, int>> meetings;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second == b.second ?
		a.first < b.first :
		a.second < b.second;
}

int solution()
{
	sort(meetings.begin(), meetings.end(), cmp);
	
	int count = 1;
	int endT = meetings[0].second;
	for (int i = 1; i < c; ++i)
	{
		if (endT > meetings[i].first)
			continue;

		++count;
		endT = meetings[i].second;
	}

	return count;
}

int main()
{
	scanf("%d", &c);

	for (int i = 0; i < c; ++i)
	{
		pair<int, int> m;
		scanf("%d %d", &m.first, &m.second);

		meetings.push_back(m);
	}

	printf("%d", solution());

	return 0;
}