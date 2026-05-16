#include <string>
#include <vector>

using namespace std;

int dp[2001] = {0};
int fibo(int n)
{
    if(dp[n] != 0)
        return dp[n];
    if(n == 1 || n == 2)
    {
        dp[n] = n;
        return n;
    }
    
    dp[n] = (fibo(n - 1) + fibo(n - 2)) % 1234567;
    return dp[n];
}

long long solution(int n) {
    return fibo(n);
}