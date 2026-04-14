#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> q;
	while (n-- > 0)
	{
		unsigned long long t;
		cin >> t;

		if (t == 0)
		{
			if (q.empty() == true)
			{
				cout << "0\n";
			}
			else 
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(t);
		}
	}

	return 0;
}