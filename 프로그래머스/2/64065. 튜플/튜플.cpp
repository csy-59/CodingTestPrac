#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<int>> GetNumbers(string& s)
{
    vector<vector<int>> result;

    string temp = "";
    for(int i = 1, size = s.length(); i < size - 1; ++i)
    {
        if(s[i] == '{')
        {
            vector<int> t;
            result.push_back(t);
            continue;
        }
        
        if(s[i] == '}' || s[i] == ',')
        {
            if(temp.length() > 0)
            {
                result[result.size() - 1].push_back(stoi(temp));
                temp = "";
            }
            continue;
        }
        
        temp.push_back(s[i]);
    }
    
    return result;
}

bool cmp(vector<int>& a, vector<int>& b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> t = GetNumbers(s);
    sort(t.begin(), t.end(), cmp);
    
    unordered_set<int> tuple;
    for(int i = 0, size = t.size(); i < size; ++i)
    {
        for(int j = 0, l = t[i].size(); j < l; ++j)
        {
            if(tuple.find(t[i][j]) == tuple.end())
            {
                tuple.insert(t[i][j]);
                answer.push_back(t[i][j]);
            }
        }
    }
    
    return answer;
}