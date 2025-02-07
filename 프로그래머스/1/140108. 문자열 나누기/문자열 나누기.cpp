#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int notCount = 0;
    int count = 0;
    char preChar = '\0';
    for(int i = 0, size = s.length(); i < size; ++i)
    {
        if(preChar == '\0')
        {
            preChar = s[i];
            ++count;
        }
        else if(preChar == s[i])
        {
            ++count;
        }
        else if(preChar != s[i])
        {
            ++notCount;
            if(count == notCount)
            {
                ++answer;
                preChar = '\0';
                notCount = count = 0;
            }
        }
    }
    
    if(preChar != '\0')
        ++answer;
    
    return answer;
}