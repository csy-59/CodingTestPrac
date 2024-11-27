#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> c_map;
    
    for(int i = 0, size = completion.size(); i < size;++i)
    {
        string name = completion[i];
        auto iter = c_map.find(completion[i]);
        if(iter != c_map.end())
        {
            iter->second += 1;
        }
        else
        {
            c_map[name] = 1;
        }
    }
       
    for(int i = 0, size = participant.size(); i < size; ++i)
    {
        string name = participant[i];
        auto iter = c_map.find(participant[i]);
        if(iter != c_map.end())
        {
            iter->second -= 1;
            if(iter->second <= 0)
                c_map.erase(iter);
        }
        else
        {
            return name;
        }
    }
    
    return completion[0];
}