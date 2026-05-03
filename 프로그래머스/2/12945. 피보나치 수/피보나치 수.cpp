#include <string>
#include <cstring>
#include <vector>

using namespace std;

int fibo[100001] = { 0 };
int fibonacci(int n)
{
    if(fibo[n] >= 0)
    {
        return fibo[n];
    }
    
    int num = fibonacci(n - 1) + fibonacci(n - 2);
    if(num > 1234567)
    {
        num %= 1234567;
    }
    
    fibo[n] = num;
    return num;
}

int solution(int n) {
    
    memset(fibo, -1, sizeof(fibo));
    fibo[0] = 0;
    fibo[1] = 1;
    
    return fibonacci(n);
}