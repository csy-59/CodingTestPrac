#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int buildingTime[1000];
vector<int> graph[1000];
int indegree[1000];
int dp[1000];

int solution(int w, int n)
{
	for (int i = 0; i < n; ++i)
	{
		dp[i] = buildingTime[i];
	}

	queue<int> candidate;
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i] == 0)
			candidate.push(i);
	}

	while (candidate.empty() == false)
	{
		int cur = candidate.front(); candidate.pop();

		for (int i = 0, size = graph[cur].size(); i < size; ++i)
		{
			int next = graph[cur][i];
			int timeC = dp[cur] + buildingTime[next];
			if (dp[next] < timeC)
				dp[next] = timeC;

			if (--indegree[next] == 0)
			{
				candidate.push(next);
			}
		}
	}

	return dp[w];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t > 0)
	{
		--t;

		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; ++i)
		{
			cin >> buildingTime[i];
			graph[i].clear();
		}
		memset(indegree, 0, sizeof(indegree));

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			graph[--x].push_back(--y);
			++indegree[y];
		}

		int w;
		cin >> w;
		cout << solution(w - 1, n) << "\n";
	}

	return 0;
}