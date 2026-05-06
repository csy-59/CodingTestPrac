#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    
    stack<char> st;
    
    for(int i = 0; i < s.length(); ++i)
    {
        char curCh = s[i];
        
        if(st.empty())
        {
            st.push(curCh);
            continue;
        }
        
        char prevCh = st.top();
        if (curCh != prevCh)
        {
            st.push(curCh);
            continue;
        }
        
        st.pop();
    }

    return st.empty() ? 1 : 0;
}