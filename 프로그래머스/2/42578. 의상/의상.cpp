#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int ans = 1;
    
    map<string, int> map;
    
    for(int i = 0; i < clothes.size(); ++i)
    {
        if(map.find(clothes[i][1]) == map.end())
        {
            map[clothes[i][1]] = 2;
        }
        else
        {
            ++map[clothes[i][1]];
        }
    }
    
    for(auto iter = map.begin(); iter != map.end(); ++iter)
    {
        ans *= iter->second;
    }
    
    --ans;
    
    return ans;
}