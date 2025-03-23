#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int nums[10] { 0, };
    
    while(n > 0)
    {
        ++nums[n % 10];
        n /= 10;
    }
    
    for(int i = 9; i > -1; --i)
    {
        for(int j = 0; j < nums[i]; ++j)
        {
            answer = answer * 10 + i;
        }
    }
    
    return answer;
}