#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i = 0, count = n / 2; i < count; ++i)
    {
        answer.append("수박");
    }
    if(n % 2 == 1) answer.append("수");
    return answer;
}