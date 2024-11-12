#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	return a > b;
}

int main()
{
	map<string, bool> m;
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		string name;
		char type[6];
		cin >> name >> type;
		m[name] = (strcmp(type, "enter") == 0);
	}

	vector<string> v;
	for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		if (iter->second == true)
		{
			v.push_back(iter->first);
		}
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << "\n";
	}

	return 0;
}