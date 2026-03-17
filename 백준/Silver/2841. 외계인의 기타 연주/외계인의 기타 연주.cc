#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;
	cin >> n >> p;

	unordered_map<int, stack<int>> map;
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		int s, num;
		cin >> s >> num;

		if (map.find(s) == map.end())
		{
			++result;
			map[s].push(num);
		}
		else
		{
			while (map[s].empty() == false && map[s].top() > num)
			{
				++result;
				map[s].pop();
			}

			if (map[s].empty() == true || map[s].top() != num)
			{
				++result;
				map[s].push(num);
			}
		}
	}

	cout << result;

	return 0;
}