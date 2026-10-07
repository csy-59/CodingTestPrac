#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string, int> m;
    string alpha = "A";
    for(int i = 1; i < 27; ++i)
    {
        m[alpha] = i;
        ++alpha[0];
    }
    
    int longestWord = 1;
    int index = 0;
    while(index < msg.length())
    {
        string str;
        int wordSize = 0;
        for(int i = longestWord; i > 0; --i)
        {
            str = msg.substr(index, i);
            if(m.find(str) != m.end())
            {
                longestWord = max(i + 1, longestWord);
                answer.push_back(m[str]);
                m[msg.substr(index, i + 1)] = m.size() + 1;
                wordSize = i;
                break;
            }
        }
        
        index += wordSize;
    }
    
    return answer;
}