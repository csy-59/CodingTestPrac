#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> Split(string str)
{
    vector<string> result;
    for(int i = 0, length = str.length(); i < length; ++i)
    {
        if(str[i] == ' ')
        {
            result.push_back(str.substr(0, i));
            result.push_back(str.substr(i + 1, length));
            return result;
        }
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    int userCount = id_list.size();
    unordered_map<string, int> id2Index;
    vector<unordered_set<string>> reportCount(id_list.size());
    vector<unordered_set<string>> reportList(id_list.size());
    
    for(int i = 0; i < userCount; ++i)
    {
        id2Index[id_list[i]] = i;
    }
    
    for(int i = 0, size = report.size(); i < size; ++i)
    {
        vector<string> reportLog = Split(report[i]);
        reportList[id2Index[reportLog[0]]].insert(reportLog[1]);
        reportCount[id2Index[reportLog[1]]].insert(reportLog[0]);
    }
    
    vector<string> blockUser;
    for(int i = 0; i < userCount; ++i)
    {
        int count = reportCount[i].size();
        if(count >= k)
            blockUser.push_back(id_list[i]);
    }
    
    int blockUserCount = blockUser.size();
    for(int i = 0; i < userCount; ++i)
    {
        int count = 0;
        for(int j = 0; j < blockUserCount; ++j)
        {
            if(reportList[i].find(blockUser[j]) != reportList[i].end())
            {
                ++count;
            }
        }
        answer.push_back(count);
    }
        
    
    return answer;
}