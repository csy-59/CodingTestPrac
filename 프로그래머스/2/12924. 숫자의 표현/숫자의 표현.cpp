#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int numCount = 1;
    int offsetSum = 0;
    while(true)
    {
        if((n - offsetSum) % numCount == 0)
        {
            ++answer;
        }
        
        offsetSum += numCount;
        ++numCount;
        
        if(offsetSum >= n)
            break;
    }
    
    return answer;
}