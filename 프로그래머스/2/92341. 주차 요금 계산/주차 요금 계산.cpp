#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

const int FullTime = 23 * 60 + 59;

void GetInfo(string str, string& time, int& carNum, bool& isIn)
{
    time = str.substr(0, 5);
    carNum = stoi(str.substr(6, 4));
    isIn = str.substr(11, 2).compare("IN") == 0;
}

int GetMin(string time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> times;
    unordered_map<int, int> inCars;
    
    for(int i = 0, size = records.size(); i < size; ++i)
    {
        string t; int carNum = 0; bool isIn;
        GetInfo(records[i], t, carNum, isIn);
        
        if(isIn)
        {
            inCars[carNum] = GetMin(t);
        }
        else
        {
            if(times.find(carNum) == times.end()) times[carNum] = 0;
            times[carNum] += GetMin(t) - inCars[carNum];
            
            inCars.erase(carNum);
        }
    }
    
    for(auto iter = inCars.begin(); iter != inCars.end(); ++iter)
    {
            if(times.find(iter->first) == times.end()) times[iter->first] = 0;
            times[iter->first] += FullTime - iter->second;
    }
    
    for(auto iter = times.begin(); iter != times.end(); ++iter)
    {
        int fee = fees[1] + (iter->second < fees[0] ? 0 : (ceil((iter->second - fees[0]) / (float)fees[2]) * fees[3]));
        answer.push_back(fee);
    }
    
    return answer;
}