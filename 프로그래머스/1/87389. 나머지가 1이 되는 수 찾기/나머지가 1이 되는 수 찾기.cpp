#include <string>
#include <vector>

using namespace std;

int findNum(int n)
{
    for(int i = 2 ; i < n / 2; ++i)
    {
        if(n % i == 0)
            return i;
    }
    
    return n;
}

int solution(int n) {
    return findNum(n - 1);
}