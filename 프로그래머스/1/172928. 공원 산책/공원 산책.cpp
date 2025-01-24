#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int x, y;
    int h = park.size(), w = park[0].length();
    for(int i = 0, size = park.size(); i < size; ++i)
    {
        for(int j = 0, len = park[i].length(); j < len; ++j)
        {
            if(park[i][j] == 'S')
            {
                x = i;
                y = j;
            }
        }
    }
    
    for(int i = 0, size = routes.size(); i < size; ++i)
    {
        char dir = routes[i][0];
        int num = stoi(routes[i].substr(2));
        
        switch(dir)
        {
            case 'N':
                {
                    if(x - num < 0)
                        break;
                    
                    bool isThereWall = false;
                    for(int i = 1; i <= num; ++i)
                    {
                        if(park[x-i][y] == 'X')
                        {
                            isThereWall = true;
                            break;
                        }
                    }
                    
                    if(isThereWall)
                        break;
                    
                    x = x - num;
                    break;
                }
            case 'S':
                {
                    if(x + num >= h)
                        break;
                    
                    bool isThereWall = false;
                    for(int i = 1; i <= num; ++i)
                    {
                        if(park[x+i][y] == 'X')
                        {
                            isThereWall = true;
                            break;
                        }
                    }
                    
                    if(isThereWall)
                        break;
                    
                    x = x + num;
                    break;
                }
            case 'W':
                {
                    if(y - num < 0)
                        break;
                    
                    bool isThereWall = false;
                    for(int i = 1; i <= num; ++i)
                    {
                        if(park[x][y-i] == 'X')
                        {
                            isThereWall = true;
                            break;
                        }
                    }
                    
                    if(isThereWall)
                        break;
                    
                    y = y - num;
                    break;
                }
            case 'E':
                {
                    if(y + num >= w)
                        break;
                    
                    bool isThereWall = false;
                    for(int i = 1; i <= num; ++i)
                    {
                        if(park[x][y+i] == 'X')
                        {
                            isThereWall = true;
                            break;
                        }
                    }
                    
                    if(isThereWall)
                        break;
                    
                    y = y + num;
                    break;
                }
        }
    
    }
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}