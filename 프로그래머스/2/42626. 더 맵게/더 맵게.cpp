#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,
        vector<int>,
        greater<int>> q;
    for(int i = 0, size = scoville.size(); i < size; ++i)
    {
        q.push(scoville[i]);
    }
    
    while(q.empty() == false)
    {
        int first = q.top(); q.pop();
        
        if(first >= K)
            return answer;
        
        if(q.empty() == true)
            return -1;
        
        int sec = q.top(); q.pop();
        
        q.push(first + sec * 2);
        ++answer;
    }
    
    return -1;
}