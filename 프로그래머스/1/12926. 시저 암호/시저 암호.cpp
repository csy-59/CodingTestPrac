#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    int gab = 'z' - 'a' + 1;
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        char c = s[i];
        if(c == ' ')
            continue;
        
        char temp = 0;
        if(c >= 'a' && c <= 'z')
        {   
            temp = (c - 'a' + n) % 26 + 'a';
        }
        else if(c >= 'A' && c <= 'Z')
        {
            temp = (c - 'A' + n) % 26 + 'A';
        }
        s[i] = temp;
    }
    
    return s;
}