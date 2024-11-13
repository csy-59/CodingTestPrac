#include <iostream>
#include <set>

using namespace std;
int main()
{
	set<string> s;
	set<string> result;
	int notHeardCount, notSeenCount;
	cin >> notHeardCount >> notSeenCount;

	for (int i = 0; i < notHeardCount; ++i)
	{
		string str;
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < notSeenCount; ++i)
	{
		string str;
		cin >> str;
		if (s.find(str) != s.end())
		{
			result.insert(str);
		}
	}

	cout << result.size() << "\n";
	for (auto iter = result.begin(); iter != result.end(); ++iter)
	{
		cout << *iter << "\n";
	}

	return 0;
}