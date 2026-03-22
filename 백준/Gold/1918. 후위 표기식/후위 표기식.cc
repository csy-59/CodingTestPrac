#include <iostream>
#include <stack>

using namespace std;

bool isPrior(char a, char b)
{
    int pa = 0, pb = 0;

    if (a == '+' || a == '-') pa = 1;
    else if (a == '*' || a == '/') pa = 2;

    if (b == '+' || b == '-') pb = 1;
    else if (b == '*' || b == '/') pb = 2;

    return pa >= pb;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string result = "";
    stack<char> st;
    for (int i = 0, size = s.length(); i < size; ++i)
    {
        switch (s[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        {
            while (st.empty() == false && st.top() != '(' 
                && isPrior(st.top(), s[i]))
            {
                result.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
            break;
        }
        case '(':
        {
            st.push(s[i]);
            break;
        }
        case ')': 
        {
            while (st.empty() == false && st.top() != '(')
            {
                result.push_back(st.top());
                st.pop();
            }

            if (st.empty() == false)
                st.pop();

            break;
        }
        default:
        {
            result.push_back(s[i]);
            break;
        }
        }
    }

    while (st.empty() == false)
    {
        result.push_back(st.top());
        st.pop();
    }

    cout << result;

	return 0;
}
