#include <iostream>	

using namespace std;

int k;
long long solution(long long x, long long y,int time)
{
	if (time >= k) return (x + y) * 2;
	if (time % 2 == 0) return solution(x, x + y, time + 1);
	return solution(x + y, y, time + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k;
	cout << solution(1, 1, 1);

	return 0;
}