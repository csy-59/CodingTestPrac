#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> ans;
    
    map<string, bool> map;
    char prevCh = words[0][0];
    vector<int> pT(n, 0);
    int turn = 0;
    bool noL = true;
    for(int i = 0; i < words.size(); ++i)
    {
        ++pT[turn];
        if(prevCh != words[i][0])
        {
            noL = false;
            break;
        }
        
        if(map.find(words[i]) != map.end())
        {
            noL = false;
            break;
        }
        
        map[words[i]] = true;
        prevCh = words[i][words[i].length() - 1];
        turn = (turn + 1) % n;
    }
    
    if(noL)
    {
        ans.push_back(0);
        ans.push_back(0);
        return ans;
    }
    
    ans.push_back(turn + 1);
    ans.push_back(pT[turn]);
    return ans;
}