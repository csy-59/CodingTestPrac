#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int ans = 0;
    
    sort(tangerine.begin(), tangerine.end());
    vector<int> count;
    int countSize = 0;
    
    int prev = -1;
    for(int i = 0 ; i < tangerine.size(); ++i)
    {
        if(prev != tangerine[i])
        {
            count.push_back(0);
            ++countSize;
        }
        ++count[countSize - 1];
        prev = tangerine[i];
    }
    
    sort(count.begin(), count.end());
    
    for(int j = countSize - 1; j >= 0; --j)
    {
        k -= count[j];
        ++ans;
        if(k <= 0)
        {
            return ans;
        }
    }
    
    return ans;
}