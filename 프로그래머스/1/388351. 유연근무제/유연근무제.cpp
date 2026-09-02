#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int count = schedules.size();
    int answer = count;
    for(int i = 0; i < count; ++i)
    {
        int minTime = schedules[i];
        schedules[i] = (minTime % 100 >= 50 ? minTime + 100 - 50 : minTime + 10);
    }
    
    vector<bool> canGetPrize(count, true);
    for(int i = 0; i < 7; ++i)
    {
        int curDay = (startday + i) % 7;
        if(curDay == 6 || curDay == 0)
            continue;
        
        for(int j = 0; j < count; ++j)
        {
            if(canGetPrize[j] == false)
                continue;
            
            canGetPrize[j] = schedules[j] >= timelogs[j][i];
            if(canGetPrize[j] == false)
                --answer;
        }
    }
    
    return answer;
}