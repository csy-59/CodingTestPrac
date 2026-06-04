#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int DP(vector<vector<int>>& dungeons, int k, int visited, int count)
{
    int size = dungeons.size();
    
    if(count == size)
    {
        return count;
    }
    
    int newCount = count;
    for(int i = 0; i < size; ++i)
    {
        if(k < dungeons[i][0]) // 조건에 맞지않음
            continue;
        
        
        if((visited & (1 << i)) != 0) // 이미 방문함
            continue;
        
        newCount = max(newCount, DP(dungeons, k - dungeons[i][1], (visited | (1 << i)), count + 1));
    }
    
    return newCount;
}

int solution(int k, vector<vector<int>> dungeons) {    
    return DP(dungeons, k, 0, 0);
}