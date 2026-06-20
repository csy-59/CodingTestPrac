#include <iostream>
#include <string>

using namespace std;
int solution(string s)
{
    int answer = 0;
    
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        int candidate = 1;
        for(int j = 1, maxLen = min(i, size - i - 1); j <= maxLen; ++j)
        {
            if(s[i + j] != s[i - j]) break;
            candidate += 2;
        }
        answer = max(answer, candidate);
        
        if(s[i] != s[i + 1]) continue;
        
        candidate = 2;
        for(int j = 1, maxLen = min(i, size - i - 2); j <= maxLen; ++j)
        {
            if(s[i + j + 1] != s[i - j]) break;
            candidate += 2;
        }
        answer = max(answer, candidate);
    }

    return answer;
}