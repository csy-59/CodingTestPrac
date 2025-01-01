#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    bool alphabet[26];
    for(int i = 0; i < 26; ++i)
    {
        alphabet[i] = true;
    }
    
    for(int i = 0, size = skip.size(); i < size; ++i)
    {
        alphabet[skip[i] - 'a'] = false;
    }
    
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        int startIndex = s[i] - 'a';
        
        int count = index;
        while(count > 0)
        {
            startIndex = (startIndex + 1) % 26;
            
            if(alphabet[startIndex] == true)
            {
                --count;
            }
        }
        
        answer += 'a' + startIndex;
    }
    
    return answer;
}