#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool answerFound = false;
void Solution(string o, string t)
{
	if (o.size() == t.size())
	{
		if(o.compare(t) == 0)
			answerFound = true;
		return;
	}

	if (t[t.length() - 1] == 'B')
	{
		reverse(t.begin(), t.end());
		t.erase(t.begin());
	}
	else
	{
		t.pop_back();
	}

	Solution(o, t);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string o, t;
	cin >> o >> t;

	Solution(o, t);
	cout << (answerFound) ? "1" : "0";

	return 0;
}