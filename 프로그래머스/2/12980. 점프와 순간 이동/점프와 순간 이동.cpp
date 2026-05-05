#include <iostream>
using namespace std;

int solution(int n)
{
    int result = 1;
    
    while(n > 1)
    {
        if(n % 2 == 1)
            ++result;
        n /= 2;
    }

    return result;
}