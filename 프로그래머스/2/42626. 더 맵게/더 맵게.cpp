#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0, size = scoville.size(); i < size; ++i)
    {
        q.push(scoville[i]);
    }
    
    while(q.top() < K)
    {
        if(q.size() < 2) return -1;
        
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        
        q.push(a + b * 2);
        
        ++answer;
    }
    
    return answer;
}