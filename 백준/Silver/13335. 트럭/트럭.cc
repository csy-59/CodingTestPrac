#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w, l;
	cin >> n >> w >> l;

	vector<int> tracks(n, 0);
	vector<int> point(n, w);

	for (int i = 0; i < n; ++i)
	{
		cin >> tracks[i];
	}

	int time = 1;
	int start = 0;
	int totalW = tracks[start]; --point[start];
	int next = 1;
	while (next < n)
	{
		++time;
		for (int i = start; i < next; ++i) --point[i];
		if (point[start] < 0) totalW -= tracks[start++];
		if ((totalW + tracks[next]) <= l)
		{
			totalW += tracks[next]; --point[next];
			++next;
		}
	}

	// 마지막 트럭의 남은 이동 횟수
	std::cout << time + point[next - 1] + 1;

	return 0;
}