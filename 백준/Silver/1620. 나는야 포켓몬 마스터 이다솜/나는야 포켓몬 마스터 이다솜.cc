#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	unordered_map<string, int> dict;
	vector<string> v;

	int n, m;
	cin >> n >> m;
	v.reserve(n + 1);
	v.push_back("");
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		v.push_back(str);
		dict[str] = i + 1;
	}

	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;

		if (atoi(str.c_str()) > 0)
		{
			cout << v[atoi(str.c_str())] << "\n";
		}
		else
		{
			cout << dict[str] << "\n";
		}
	}

	return 0;
}