#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    for(int i = 0, size = players.size(); i < size; ++i)
    {
        if(players[i] >= m)
        {
            int upgradeCount = players[i] / m;
            for(int j = i, max = i + k; j < max; ++j)
            {
                if(j >= size)
                    break;
                players[j] -= m * upgradeCount;
            }
            answer += upgradeCount;
        }
    }
    
    return answer;
}