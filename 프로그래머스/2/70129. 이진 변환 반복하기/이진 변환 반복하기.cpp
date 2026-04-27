#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int subZeroCount = 0;
int ltobCount = 0;

string SubZero(string s)
{
    for (auto iter = s.find('0'); iter != string::npos; iter = s.find('0'))
    {
        ++subZeroCount;
        s.erase(iter, 1);
    }

    return s;
}

bool LToB(string& s)
{
    int size = s.length();
    s = "";

    bool isChanged = false;
    while (size > 1)
    {
        isChanged = true;
        s.push_back((size % 2 == 1 ? '1' : '0'));
        size /= 2;
    }

    s.push_back((size == 1 ? '1' : '0'));
    reverse(s.begin(), s.end());

    if (isChanged) ++ltobCount;

    return isChanged;
}

vector<int> solution(string s) {
    vector<int> answer;

    ltobCount = subZeroCount = 0;
    
    s = SubZero(s);
    while (LToB(s) == true)
        s = SubZero(s);

    answer.push_back(ltobCount + 1);
    answer.push_back(subZeroCount);

    return answer;
}