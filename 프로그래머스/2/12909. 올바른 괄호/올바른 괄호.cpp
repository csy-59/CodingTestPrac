#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{    
    int openCount = 0;
    for(int i = 0, length = s.length(); i < length; ++i)
    {
        if(s[i] == '(') ++openCount;
        else if(openCount > 0) --openCount;
        else return false;
    }

    return openCount == 0;
}