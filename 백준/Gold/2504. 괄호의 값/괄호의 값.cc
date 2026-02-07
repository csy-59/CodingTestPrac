#include <iostream>	
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;
    stack<pair<int, int>> score;
    int result = 0;
    for (int i = 0, size = s.size(); i < size; ++i)
    {
        char curP = s[i];

        if (curP == '(' || curP == '[')
        {
            st.push(curP);
            continue;
        }

        if (st.empty() == true ||
            curP == ')' && st.top() != '(' ||
            curP == ']' && st.top() != '[')
        {
            cout << 0;
            return 0;
        }

        int depth = st.size(); st.pop();
        int temp = 0;
        while (score.empty() == false && score.top().first > depth)
        {
            temp += score.top().second;
            score.pop();
        }

        if (temp != 0)
        {
            temp = temp * (curP == ')' ? 2 : 3);
        }
        else
        {
            temp = curP == ')' ? 2 : 3;
        }

        score.push(make_pair(depth, temp));
    }

    if (st.empty() == false)
    {
        cout << 0;
        return 0;
    }

    while (score.empty() == false)
    {
        result += score.top().second;
        score.pop();
    }

    cout << result;

	return 0;
}