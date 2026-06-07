#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    
    int jobCount = progresses.size();
    for(int i = 0; i < jobCount; ++i)
    {
        if(progresses[i] >= 100) continue; // 이미 배포 완료
        
        int finDate = (int) ceil((100 - progresses[i]) / (float)speeds[i]);
        int finCount = 0;
        bool preJobDone = true;
        for(int j = i; j < jobCount; ++j)
        {
            progresses[j] += speeds[j] * finDate;
            if(preJobDone == true && progresses[j] >= 100)
                ++finCount;
            else
                preJobDone = false;
        }
        ans.push_back(finCount);
    }
    
    return ans;
}