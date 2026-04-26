#include<string>
#include<stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        if(s[i] == '(') st.push(s[i]);
        else if(st.empty() == true) return false;
        else st.pop();
    }
    return st.empty();
}