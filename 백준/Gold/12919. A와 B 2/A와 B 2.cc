#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int solution(string a, string b)
{
	stack<string> t;
	t.push(b);

	string newB;
	string newString;
	while (t.empty() == false)
	{
		newB = t.top();
		t.pop();

		if (a.compare(newB) == 0) return 1;
		if (a.size() >= newB.size()) continue;

		if (newB[newB.size() - 1] == 'A')
		{
			newString = newB;
			newString.erase(newB.size() - 1);
			t.push(newString);
		}
		if (newB[0] == 'B')
		{
			newString = newB;
			newString.erase(newString.begin());
			reverse(newString.begin(), newString.end());
			t.push(newString);
		}
	}

	return 0;
}

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;

	cout << solution(s, t);

	return 0;
}