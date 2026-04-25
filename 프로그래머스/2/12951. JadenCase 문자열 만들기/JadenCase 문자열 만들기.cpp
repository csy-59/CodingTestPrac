#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string s) {
    
    for(int i = 1; i < s.length(); ++i)
    {
        if(s[i - 1] == ' ' && isdigit(s[i]) == 0)
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
    
    if(isdigit(s[0]) == 0)
    {
        s[0] = toupper(s[0]);
    }
    
    return s;
}