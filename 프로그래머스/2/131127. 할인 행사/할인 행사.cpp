#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int ans = 0;
    
    map<string, int> m;
    
    int totalAmount = 0;
    int wantSize = want.size();
    for(int i = 0; i < wantSize; ++i)
    {
        totalAmount += number[i];
        m[want[i]] = number[i];
    }
    
    int disSize = discount.size();
    for(int i = 0; i < disSize - 9; ++i)
    {
        int total = totalAmount;
        for(int j = 0; j < 10; ++j)
        {
            auto iter = m.find(discount[i + j]);
            if(iter != m.end() && iter->second > 0)
            {
                --total;
                --iter->second;
            }
        }
        
        for(int j = 0; j < wantSize; ++j)
        {
            m[want[j]] = number[j];
        }
        
        if(total <= 0)
            ++ans;
    }
    
    return ans;
}