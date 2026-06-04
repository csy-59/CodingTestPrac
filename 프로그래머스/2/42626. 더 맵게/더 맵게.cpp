#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    int foodCount = scoville.size();
    priority_queue<int, vector<int>, greater<int>> foods;
    
    for(int i = 0; i < foodCount; ++i)
    {
        foods.push(scoville[i]);
    }
    
    while(foods.empty() == false && foods.top() < K)
    {
        int first = foods.top(); foods.pop();
        
        if(foods.empty() == true) return -1; // 변환 가능한 음식이 남아있지 않음
        
        int second = foods.top(); foods.pop();
        
        foods.push(first + second * 2);
        ++answer;
    }
    
    return answer;
}