#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

vector<string> split(string str)
{
    vector<string> result;
    int count = str.size();
    int start = 0;
    for(int i= 0; i< count; ++i)
    {
        if(str[i] == ' ')
        {
            result.push_back(str.substr(start, i));
            start = i+ 1;
        }
    }
    result.push_back(str.substr(start));
    
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int friends_len = friends.size();
    int gifts_len = gifts.size();
    
    unordered_map<string, int> m;
    for(int i = 0; i< friends_len; ++i)
    {
        m[friends[i]] = i;
    }
    
    int giftCounts[50][50] = {0, };
    int giftTimes[50][2] = {0,};
    for(int i = 0; i < gifts_len; ++i)
    {
        string str = gifts[i];
        vector<string> names = split(str);
        string n1 = names[0];
        string n2 = names[1];
        
        int giver = m[n1];
        int reciver = m[n2];
        
        giftCounts[giver][reciver] += 1;
        giftTimes[giver][0] += 1;
        giftTimes[reciver][1] += 1;
    }
    
    int results[50] = {0,};
    for(int i = 0; i<friends_len; ++i)
    {
        results[i] = 0;
        for(int j = 0; j<friends_len; ++j)
        {
            if(i == j) continue;
            if(giftCounts[i][j] > giftCounts[j][i])
            {
                results[i] += 1;
            }
            else if(giftCounts[i][j] == giftCounts[j][i])
            {
                int iGift = giftTimes[i][0] - giftTimes[i][1];
                int jGift = giftTimes[j][0] - giftTimes[j][1];
                
                if(iGift > jGift)
                {
                    results[i] += 1;
                }
            }
        }
    }
    
    int max = -1;
    for(int i = 0; i<friends_len; ++i)
    {
        if(results[i] > max)
            max = results[i];
    }
    
    return max;
}