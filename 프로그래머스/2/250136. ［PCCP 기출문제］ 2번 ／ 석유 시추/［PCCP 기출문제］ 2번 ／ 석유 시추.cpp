#include <string>
#include <vector>
#include <queue>

using namespace std;

int oilCounts[501] = { 0, };
bool isVisited[501][501] = {false};

int oilCount(const vector<vector<int>>& land, pair<int, int>& point)
{
    int result = 0;
    
    int h = land.size();
    int w = land[0].size();
    
    int min = 501, max = -1;
    
    queue<pair<int, int>> q;
    q.emplace(point.first, point.second);
    
    while(q.empty() == false)
    {
        pair<int, int> newPoint = q.front();
        q.pop();
        
        if(isVisited[newPoint.first][newPoint.second] == true)
            continue;
        
        result += 1;
        isVisited[newPoint.first][newPoint.second] = true;
        
        if(min > newPoint.second)
            min = newPoint.second;
        if(max < newPoint.second)
            max = newPoint.second;
        
        if(newPoint.first > 0 && land[newPoint.first - 1][newPoint.second] == 1)
        {
            q.emplace(newPoint.first - 1, newPoint.second);
        }
        
        if(newPoint.second > 0 && land[newPoint.first][newPoint.second - 1] == 1)
        {
            q.emplace(newPoint.first, newPoint.second - 1);
        }
        
        if(newPoint.first < h - 1 && land[newPoint.first + 1][newPoint.second] == 1)
        {
            q.emplace(newPoint.first + 1, newPoint.second);
        }
        
        if(newPoint.second < w - 1 && land[newPoint.first][newPoint.second + 1] == 1)
        {
            q.emplace(newPoint.first, newPoint.second + 1);
        }
    }
    
    for(int i = min; i <= max; ++i)
    {
        oilCounts[i] += result;
    }
    
    return result;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int h = land.size();
    int w = land[0].size();
    
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            if(isVisited[i][j] == true)
                continue;
            
            if(land[i][j] == 0)
                continue;
            
            pair<int, int> p;
            p.first = i;
            p.second = j;
            oilCount(land, p);
        }
    }
    
    int max = -1;
    for(int i = 0; i < w; ++i)
    {
        if(oilCounts[i] > max)
            max = oilCounts[i];
    }
    
    return max;
}