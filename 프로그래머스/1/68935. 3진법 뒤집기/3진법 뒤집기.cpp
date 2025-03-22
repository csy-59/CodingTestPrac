#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    long long changeNum = 0;
    while(n > 0)
    {
        changeNum = changeNum * 10 + n % 3;
        n /= 3;
    }
    
    int three = 1;
    while(changeNum > 0)
    {
        answer += (changeNum % 10) * three;
        three *= 3;
        changeNum /= 10;
    }
    
    return answer;
}