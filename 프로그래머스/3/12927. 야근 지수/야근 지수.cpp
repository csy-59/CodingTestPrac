#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long result = 0;
    
    priority_queue<int> q;
    int total = 0;
    for(int i = 0, size = works.size(); i < size; ++i)
    {
        total += works[i];
        q.push(works[i]);
    }
    
    if(n >= total)
        return result;
    
    for(int i = 0; i < n; ++i)
    {
        int max = q.top();
        q.pop();
        q.push(max - 1);
    }
    
    while(q.empty() == false)
    {
        int num = q.top();
        q.pop();
        result += num * num;
    }
    
    return result;
}