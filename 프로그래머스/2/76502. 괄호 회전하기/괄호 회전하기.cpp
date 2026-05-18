#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int ans = 0;
    int size = s.length();
    
    for(int i = 0; i < size; ++i)
    {
        bool isValied = true;
        int curIndex = i;
        stack<char> st;
        do
        {
            char curCh = s[curIndex];
            
            if(curCh == ']')
            {
                char prevCh = st.top();
                st.pop();
                if(prevCh != '[')
                {
                    isValied = false;
                    break;
                }
            }
            else if(curCh == '}')
            {
                char prevCh = st.top();
                st.pop();
                if(prevCh != '{')
                {
                    isValied = false;
                    break;
                }
            }
            else if(curCh == ')')
            {
                char prevCh = st.top();
                st.pop();
                if(prevCh != '(')
                {
                    isValied = false;
                    break;
                }
            }
            else
            {
                st.push(curCh);
            }
            
            curIndex = (curIndex + 1) % size;
        } while(curIndex != i);
        
        if(isValied && st.size() == 0)
            ++ans;
    }
    
    return ans;
}