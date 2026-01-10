#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> computers[101];

int dfsCount()
{
	int count = 0;
	bool isVisited[101] = { false };

	std::stack<int> dfs;
	dfs.push(1);

	while (dfs.empty() == false)
	{
		int node = dfs.top();
		dfs.pop();
		if (isVisited[node] == false)
		{
			++count;
			isVisited[node] = true;
		}

		for (int i = computers[node].size() - 1; i >= 0; --i)
		{
			if (isVisited[computers[node][i]] == false)
			{
				dfs.push(computers[node][i]);
			}
		}
	}

	return count;
}

int main()
{
	int computerCount, lineCount;
	scanf("%d %d", &computerCount, &lineCount);

	int start, end;
	for (int i = 0; i < lineCount; ++i)
	{
		scanf("%d %d", &start, &end);
		computers[start].push_back(end);
		computers[end].push_back(start);
	}

	printf("%d", dfsCount() - 1);

	return 0;
}