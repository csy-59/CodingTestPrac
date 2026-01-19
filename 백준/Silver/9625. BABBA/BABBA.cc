#include <iostream>

using namespace std;

int k;
pair<int, int> GetCount(pair<int, int> set, int time)
{
	if (time == k) return set;
	return GetCount(make_pair(set.second, set.first + set.second), ++time);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k;

	auto result = GetCount(make_pair(1, 0), 0);
	cout << result.first << " " << result.second;

	return 0;
}