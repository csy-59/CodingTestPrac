#include <iostream>
#include <vector>

using namespace std;

int n;
int cand[4] = { 1,3,7,9 };
int start[4] = { 2,3,5,7 };

bool isPrime(int x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0) return false;
	}
	return true;
}

void DFS(int num, int len)
{
	if (len == n)
	{
		cout << num << "\n";
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int newNum = num * 10 + cand[i];
		if (isPrime(newNum))
			DFS(newNum, len + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	if (n == 1)
	{
		for (int i = 0; i < 4; ++i)
		{
			cout << start[i] << "\n";
		}
		return 0;
	}

	for (int i = 0; i < 4; ++i)
	{
		DFS(start[i], 1);
	}

	return 0;
}