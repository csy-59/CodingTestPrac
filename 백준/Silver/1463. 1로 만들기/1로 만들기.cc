#include <stdio.h>
#include <queue>

bool isVisited[1000001] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);

	std::queue<int> q;
	q.push(n);
	isVisited[n] = true;

	int c = 0, size = q.size();
	while (q.empty() == false)
	{
		int num = q.front();
		q.pop(); --size;

		//printf("%d ", num);

		if (num == 1)
			break;
		
		if (num % 3 == 0 && isVisited[num / 3] == false)
		{
			isVisited[num / 3] = true;
			q.push(num / 3);
		}
		if (num % 2 == 0 && isVisited[num / 2] == false)
		{
			isVisited[num / 2] = true;
			q.push(num / 2);
		}
		if (isVisited[num - 1] == false)
		{
			isVisited[num - 1] = true;
			q.push(num - 1);
		}

		if (size == 0)
		{
			size = q.size();
			++c;
			//printf("\n");
		}
	}

	printf("%d", c);

	return 0;
}