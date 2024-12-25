#include <stdio.h>

char arr[100001] = { '\0' };

using namespace std;
int main()
{
	scanf("%s", arr);

	int answer = 0;
	int stickCount = 0;
	int index = 0;
	char prev = '\0';
	while (arr[index] != '\0')
	{
		char c = arr[index];
		if (c == '(')
		{
			stickCount += 1;
		}
		else // c == ')'
		{
			if (prev == '(')
			{
				stickCount -= 1;
				answer += stickCount;
			}
			else
			{
				stickCount -= 1;
				answer += 1;
			}
		}

		prev = c;
		++index;
	}

	printf("%d", answer);

	return 0;
}