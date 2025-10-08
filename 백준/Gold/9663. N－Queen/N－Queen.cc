#include <stdio.h>
#include <vector>

using namespace std;

int N;
int result = 0;

/// <summary>
/// NQueen 해결
/// </summary>
/// 1) 상태 표현
/// <param name="c">특정 열에 퀸이 있는지</param>
/// <param name="dp">오른쪽으로 내려가는 대각선에 퀸이 있는지(r+c)</param>
/// <param name="dm">왼쪽으로 내려가는 대각에서 퀸이 있는지(r-c+n-1)</param>
/// <param name="n">퀸을 배치할 행</param>
void NQueen(vector<bool>& c, vector<bool>& dp, vector<bool>& dm, int n)
{
	// 2) 종료 조건
	if (n == N) // 모든 퀸 배치가 끝났다면
	{
		++result;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		// 4) 유망성 검사
		if (c[i] == false && dp[n + i] == false && dm[n - i + N - 1] == false)
		{
			// 3) 후보 생성
			c[i] = true;
			dp[n + i] = true;
			dm[n - i + N - 1] = true;

			NQueen(c, dp, dm, n + 1);

			// 4) 복귀
			c[i] = false;
			dp[n + i] = false;
			dm[n - i + N - 1] = false;
		}
	}

	// 5) 일종의 가지치기 (조건에 맞지 않으면 더이상 진행하지 않음
}

int main()
{
	scanf("%d", &N);

	auto c = vector<bool>(N, false);
	auto dp = vector<bool>(2 * N - 1, false);
	auto dm = vector<bool>(2 * N - 1, false);
	NQueen(c, dp, dm, 0);
	
	printf("%d", result);

	return 0;
}