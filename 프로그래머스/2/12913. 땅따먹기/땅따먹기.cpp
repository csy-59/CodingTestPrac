#include <iostream>
#include <vector>
using namespace std;

bool isVisited[100000] = { false, };
int map[100000][4] = { 0 };

int max(int a, int b) { return a > b ? a : b; }

int f(vector<vector<int>>& land, int row, int colum)
{
    if(row == 0)
    {
        for(int i = 0; i < 4; ++i)
        {
            map[row][i] = land[row][i];
        }
        
        return map[row][colum];
    }
    else if(isVisited[row] == false)
    {
        f(land, row - 1, 0);
        for(int i = 0; i < 4; ++i)
        {
            int v = 0;
            for(int j = 0; j < 4; ++j)
            {
                if(i == j) continue;
                v = max(v, land[row][i] + map[row - 1][j]);
            }
            
            map[row][i] = v;
        }
    }
        
    isVisited[row] = true;
    return map[row][colum];
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    int size = land.size() - 1;
    for(int i = 0; i < 4; ++i)
    {
        answer = max(answer, f(land, size, i));
    }
 
    return answer;
}