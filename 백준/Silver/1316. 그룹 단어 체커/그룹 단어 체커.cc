#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int result = n;
	string s;
	unordered_set<char> set;
	char c;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;

		c = s[0];
		set.insert(c);
		for (int j = 1, size = s.size(); j < size; ++j)
		{
			if (c != s[j])
			{
				c = s[j];
				if (set.find(c) != set.end())
				{
					--result;
					break;
				}
				set.insert(c);
			}
		}

		set.clear();
	}
	cout << result;

	return 0;
}