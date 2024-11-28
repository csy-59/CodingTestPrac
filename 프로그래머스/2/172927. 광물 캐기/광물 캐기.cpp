#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mins[15][3] = {0,};
int offset[3][3] = {
    1, 1, 1,
    5, 1, 1,
    25, 5, 1
};
bool cmp(int a, int b)
{
    if(mins[a][0] != mins[b][0])
        return mins[a][0] > mins[b][0];
    if(mins[a][1] != mins[b][1])
        return mins[a][1] > mins[b][1];
    
    return mins[a][2] > mins[b][2];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int total = 0;
    for(int p : picks)
    {
        total += p;
    }
    
    vector<int> minList;
    bool isOut = false;
    for(int i = 0; i < total; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            int index = i * 5 + j;
            if(index >= minerals.size())
            {
                isOut = true;
                break;
            }
            
            string m = minerals[index];
            switch(m[0])
            {
                case 'd': mins[i][0] += 1; break;
                case 'i': mins[i][1] += 1; break;
                case 's': mins[i][2] += 1; break;
            }
        }
        
        minList.push_back(i);
        if(isOut)
            break;
    }
    
    sort(minList.begin(), minList.end(), cmp);
    
    int type = 0;
    int turn = 0;
    for(int p : picks)
    {
        for(int i = 0; i< p; ++i)
        {
            if(turn >= minList.size())
                break;
            
            int index = minList[turn];
            answer+= mins[index][0] * offset[type][0] +
                mins[index][1] * offset[type][1] +
                mins[index][2] * offset[type][2];
            
            ++turn;
        }
        ++type;
    }
    
    return answer;
}