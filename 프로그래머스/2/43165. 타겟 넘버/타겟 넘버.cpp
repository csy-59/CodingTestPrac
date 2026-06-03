#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int target) {
    int count = 0;
    
    int size = numbers.size();
    
    // 다음 인덱스, 지금까지 총합
    stack<pair<int, int>> s;
    s.push({0, 0});
    
    while(s.empty() == false)
    {
        pair<int, int> temp = s.top(); s.pop();
        
        if(temp.first == size)
        {
            if(temp.second == target) ++count;
            continue;
        }
        
        s.push({temp.first + 1, temp.second + numbers[temp.first]});
        s.push({temp.first + 1, temp.second - numbers[temp.first]});
    }
    
    return count;
}