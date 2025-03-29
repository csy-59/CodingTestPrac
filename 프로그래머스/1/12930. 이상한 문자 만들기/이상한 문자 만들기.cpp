#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int count = 0;
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        char c = s[i];
        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        {
            answer.push_back(count % 2 == 0 ? toupper(c) : tolower(c));
            ++count;
        }
        else
        {
            answer.push_back(c);
            count = 0;
        }
    }
    
    return answer;
}