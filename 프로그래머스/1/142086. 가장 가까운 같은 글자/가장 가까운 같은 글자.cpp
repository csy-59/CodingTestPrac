#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> m;
    
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        if(m.find(s[i]) == m.end())
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - m[s[i]]);
        }
        
        m[s[i]] = i;
    }
    
    return answer;
}