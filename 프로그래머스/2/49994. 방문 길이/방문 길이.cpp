#include <string>
using namespace std;

bool isVisited[11][11][4] = {false};
int addX[] = {1, -1, 0, 0};
int addY[] = {0, 0, 1, -1};
int otherDir[] = {1, 0, 3, 2};

int solution(string dirs) {
    int answer = 0;
    
    int x = 5;
    int y = 5;
    for(int i = 0; i < dirs.size(); ++i)
    {
        int dir = -1;
        switch(dirs[i])
        {
            case 'U': dir = 0; break;
            case 'D': dir = 1; break;
            case 'R': dir = 2; break;
            case 'L': dir = 3; break;
            default: break;
        }
        
        int newX = x + addX[dir];
        int newY = y + addY[dir];
        if(newX < 0 || newX >= 11 || newY < 0 || newY >= 11)
            continue;
        
        if(isVisited[newX][newY][dir] == false)
        {
            ++answer;
            isVisited[newX][newY][dir] = true;
            isVisited[x][y][otherDir[dir]] = true;
        }
        
        x = newX; y = newY;
    }
    
    return answer;
}