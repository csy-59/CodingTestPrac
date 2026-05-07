#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int maxLength = w * 2 + 1;
    int s = 0;
    for(int i = 0, size = stations.size(); i < size; ++i)
    {
        int uncovered = stations[i] - s - w - 1;
        if(uncovered > 0)
        {
            answer += (int)ceil((double)uncovered / maxLength);
        }
        
        s = stations[i] + w;
    }
    
    int uncovered = n - s;
    if( uncovered > 0)
        answer += (int)ceil((double)uncovered / maxLength);

    return answer;
}