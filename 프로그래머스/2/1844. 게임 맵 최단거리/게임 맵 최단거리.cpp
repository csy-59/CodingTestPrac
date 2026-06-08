#include<vector>
#include <queue>
using namespace std;

int dir[4][2] = 
{ 
    1, 0,
    0, 1,
    -1, 0,
    0, -1
};

struct MovePos
{
    int x, y;
    int dist;
    
    MovePos() { x = y = dist = 0; }
    MovePos(int x, int y): x(x), y(y) { dist = 0; }
};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    queue<MovePos> que;
    
    MovePos start(0, 0);
    start.dist = 1;
    maps[0][0] = 0;
    
    que.push(start);
    
    while(que.empty() == false)
    {
        MovePos p = que.front(); que.pop();
        
        if(p.x == n - 1 && p.y == m - 1)
            return p.dist;
        
        for(int i = 0; i < 4; ++i)
        {
            int newX = p.x + dir[i][0];
            int newY = p.y + dir[i][1];
            
            if(newX < 0 || newX >= n ||
              newY < 0 || newY >= m)
                continue;
            
            if(maps[newX][newY] != 1) // 벽 or 이미 방문함
                continue; 
            
            maps[newX][newY] = 0; // 방문 처리
            
            MovePos newPos(newX, newY);
            newPos.dist = p.dist + 1;
            
            que.push(newPos);
        }
    }
    
    return -1;
}