#include <string>
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

void convert(map<string, int>& m, string s)
{
    int size = s.size();
    
    for(int i = 0; i < size - 1; ++i)
    {
        if(isalpha(s[i]) == 0 || isalpha(s[i + 1]) == 0)
            continue;
        
        s[i] = toupper(s[i]); s[i+1] = toupper(s[i+1]);
        string temp = s.substr(i, 2);
        if(m.find(temp) == m.end())
            m[temp] = 0;
        
        ++m[temp];
    }
    
    return;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(string str1, string str2) {
    int ans = 0;
    
    map<string, int> m1, m2;
    convert(m1, str1);
    convert(m2, str2);
    
    double intersection = 0; // 교집합
    double uni = 0; // 합집합
    
    if(m1.size() == 0 && m2.size() == 0)
    {
        return 65536;
    }
    
    for(auto iter = m1.begin(); iter != m1.end(); ++iter)
    {
        auto findIter = m2.find(iter->first);
        if(findIter != m2.end())
        {
            intersection += min(iter->second, findIter->second);
            uni += max(iter->second, findIter->second);
        }
        else
        {
            uni += iter->second;
        }
    }
    
    for(auto iter = m2.begin(); iter != m2.end(); ++iter)
    {
        if(m1.find(iter->first) == m1.end())
        {
            uni += iter->second;
        }
    }
    
    ans = (int)(intersection / uni * 65536);
    
    return ans;
}