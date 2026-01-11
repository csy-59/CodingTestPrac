#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n);
	vector<int> indegree(n, 0);
	vector<int> result(n, 0);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		++indegree[b - 1];
	}

	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i] == 0) q.push(i);
	}

	int time = 0;
	int size = 0;
	while (q.empty() == false)
	{
		if (size == 0)
		{
			size = q.size();
			++time;
		}

		int num = q.front(); q.pop();
		--size;

		result[num] = time;
		for (int i = 0, s = graph[num].size(); i < s; ++i)
		{
			if (--indegree[graph[num][i]] <= 0)
				q.push(graph[num][i]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << (result[i] > 0 ? result[i] : 1) << " ";
	}

	return 0;
}