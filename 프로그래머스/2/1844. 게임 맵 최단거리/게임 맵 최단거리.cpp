#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class point{
public: 
    int x; int y; int steps;
    point() { x = y = steps = 0; }
    point(int x, int y): x(x), y(y), steps(0) {}
    point(int x, int y, int s): x(x), y(y), steps(s) {}
};

// 이동 방향
int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};


int solution(vector<vector<int> > maps)
{
    queue<point> q;
    q.push(point(0, 0));
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> isVisited(n, vector<bool>(m));
    
    while(q.empty() == false)
    {
        point p = q.front(); q.pop();
        ++p.steps;
        
        // 목표 지점 도착
        if(p.x + 1 == n && p.y + 1 == m) 
            return p.steps;
        
        // 방향 탐색
        for(int i = 0 ; i < 4; ++i)
        {
            int newX = p.x + dir[i][0];
            int newY = p.y + dir[i][1];
            
            // 범위 조정
            if(newX < 0 || newX >= n ||
              newY < 0 || newY >= m)
                continue;
            
            // 조건 판정
            if(isVisited[newX][newY] == false &&
              maps[newX][newY] == 1)
            {
                isVisited[newX][newY] = true;
                q.push(point(newX, newY, p.steps));
            }
        }
    }
    
    return -1;
}