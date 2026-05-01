#include <string>
#include <vector>
#include <stack>

using namespace std;

int htob(int n)
{
    int ans = 0;
    while(n > 0)
    {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}

int solution(int n) {
    int myOne = htob(n);
    int next = 0;
    do{
        ++n;
        next = htob(n);
    } while( myOne != next);
    
    return n;
}