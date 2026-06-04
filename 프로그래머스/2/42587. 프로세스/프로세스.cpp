#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct process
{
    int location;
    int priority;
    
    process(): location(0), priority(0) {}
    process(int loc, int pri): location(loc), priority(pri) {}
};

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    int pCount = priorities.size(); // 프로세스 갯수
    
    deque<process> q;
    for(int i = 0; i < pCount; ++i)
    {
        q.push_back(process(i, priorities[i]));
    }
    
    // 정렬
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    int priorityIndex = 0; // 우선순위 인덱스
    while(q.empty() == false)
    {
        auto top = q.front();
        
        while(top.priority != priorities[priorityIndex])
        {
            q.pop_front(); q.push_back(top); top = q.front();
        }
        
        if(top.location == location) return answer;
        q.pop_front();
        ++answer; ++priorityIndex;
    }
    
    return answer;
}