#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

long long GetTime(const vector<int>& diffs, const vector<int>& times, int level)
{
    long long time = 0;
    
    for(int i = 0, size = diffs.size(); i < size; ++i)
    {
        int difficulty = diffs[i];
        if(difficulty <= level)
        {
            time += times[i];
        }
        else
        {
            time += (times[i] + times[i - 1]) * (difficulty - level) + times[i];
        }
    }
    
    return time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    int start = 1, end = 1;
    for(int i = 0, size = diffs.size(); i < size; ++i)
    {
        if(end < diffs[i]) end = diffs[i];
    }
    
    long long time;
    int level = 0;
    while(start < end)
    {
        level = (start + end) / 2;
        
        time = GetTime(diffs, times, level);
        
        if(time == limit)
            return level;
        else if(time > limit)
            start = level + 1;
        else
            end = level - 1;
    }
    
    if(GetTime(diffs, times, start) > limit)
        return start + 1;
    
    return start;
}