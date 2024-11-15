#include <iostream>
#include <unordered_set>
#include <string.h>

using namespace std;
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	unordered_set<string> s;

	string str;
	cin >> str;
	
	int strLength = str.length();
	for (int i = 1; i <= strLength; ++i)
	{
		for (int j = 0; j < strLength - i + 1; ++j)
		{
			s.insert(str.substr(j, i));
		}
	}

	cout << s.size();

	return 0;
}