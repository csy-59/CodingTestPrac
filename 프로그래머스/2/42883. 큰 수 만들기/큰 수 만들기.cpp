#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for(int i = 0, len = number.length(); i < len; ++i)
    {
        int newNum = number[i] - '0';
        while(k > 0 && answer.length() > 0)
        {
            int preNum = answer[answer.length() - 1] - '0';
            if(newNum > preNum)
            {
                answer.pop_back();
                --k;
            }
            else
            {
                break;
            }
        }
        answer.push_back(number[i]);
    }
    
    while(k-- > 0)
    {
        answer.pop_back();
    }
    
    return answer;
}