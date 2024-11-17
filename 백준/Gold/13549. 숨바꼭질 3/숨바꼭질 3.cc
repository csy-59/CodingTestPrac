#include <stdio.h>
#include <queue>

int minTimeArr[100001];
int solution(int n, int k)
{
	for (int i = 1; i < 100001; ++i) 
	{
		minTimeArr[i] = -1;
	}

	std::queue<int> q;
	minTimeArr[n] = 0;
	q.push(n);

	int maxTime = k - n;
	if (maxTime < 0)
	{
		return -maxTime;
	}

	int minTime = maxTime;
	while (q.empty() != true)
	{
		int newN = q.front();
		int time = minTimeArr[newN];
		if (newN == k && time < minTime)
		{
			minTime = time;
		}
		q.pop();
		//printf("%d, %d\n", newN, time);

		if (newN * 2 <= k + 1)
		{
			if (minTimeArr[newN * 2] == -1 || time < minTimeArr[newN * 2])
			{
				q.push(newN * 2);
				minTimeArr[newN * 2] = time;
			}
		}
		if (time + 1 < maxTime)
		{
			if (newN + 1 <= k)
			{
				if (minTimeArr[newN + 1] == -1 || time + 1 < minTimeArr[newN + 1])
				{
					q.push(newN + 1);
					minTimeArr[newN + 1] = time + 1;
				}
			}
			if (newN - 1 >= 0)
			{
				if (minTimeArr[newN - 1] == -1 || time + 1 < minTimeArr[newN - 1])
				{
					q.push(newN - 1);
					minTimeArr[newN - 1] = time + 1;
				}

			}
		}
	}

	return minTime;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", solution(n, k));

	return 0;
}