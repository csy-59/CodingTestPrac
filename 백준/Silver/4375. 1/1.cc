#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n)
	{
		int count = 1;
		int num = 1 % n;

		while (num != 0)
		{
			num = (num * 10 + 1) % n;
			++count;
		}

		cout << count << "\n";
	}

	return 0;
}