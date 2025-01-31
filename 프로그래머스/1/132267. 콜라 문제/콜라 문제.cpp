#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a)
    {
        int newBottle = n / a * b;
        answer += newBottle;
        n = newBottle + n % a;
    }
    
    return answer;
}