#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int pCount = 0;
    int yCount = 0;
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        if(s[i] == 'p' || s[i] == 'P')
        {
            ++pCount;
        }
        else if(s[i] == 'y' || s[i] == 'Y')
        {
            ++yCount;
        }
    }
    
    return pCount == yCount;
}