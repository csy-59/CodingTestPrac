#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int h = wallpaper.size();
    int w = wallpaper[0].size();
    pair<int, int> minPos = make_pair(h, w);
    pair<int, int> maxPos = make_pair(0, 0);
    
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            if(wallpaper[i][j] != '#') continue;
            
            if(minPos.first > i) minPos.first = i;
            if(minPos.second > j) minPos.second = j;
            if(maxPos.first < i) maxPos.first = i;
            if(maxPos.second < j) maxPos.second = j;
        }
    }
    
    answer.push_back(minPos.first); answer.push_back(minPos.second); 
    answer.push_back(maxPos.first + 1); answer.push_back(maxPos.second + 1); 
    
    return answer;
}