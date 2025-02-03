#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int min(int a, int b)
{
    return a < b? a: b;
}

string solution(string X, string Y) {
    string answer = "";

    int xM[10] = {0,};
    int yM[10] = {0,};
    for(int i = 0, size = X.length(); i < size; ++i)
    {
        ++xM[X[i] - '0'];
    }
    for(int i = 0, size = Y.length(); i < size; ++i)
    {
        ++yM[Y[i] - '0'];
    }
    
    for(int i = 9; i >= 0; --i)
    {
        if(xM[i] == 0 || yM[i] == 0)
            continue;
        
        for(int j = 0, count = min(xM[i], yM[i]); j < count; ++j)
        {
            answer.append(to_string(i));
        }
    }
    
    if(answer[0] == '0') answer = "0";
    
    return answer.length() <= 0 ? "-1" : answer;
}