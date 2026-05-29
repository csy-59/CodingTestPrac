#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    int size = citations.size();
    for(int h = citations[0]; h >= 0; --h)
    {
        int over = 0;
        
        while(over < size && citations[over] >= h)
            ++over;
        
        int under = size - over;
        
        if(over >= h && under <= h)
            return h;
    }
    
    return answer;
}