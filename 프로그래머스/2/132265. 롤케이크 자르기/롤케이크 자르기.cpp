#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> mine;
    mine[topping[0]] = 1;
    unordered_map<int, int> sibling;
    
    for(int i = 1, size = topping.size(); i < size; ++i)
    {
        int top = topping[i];
        if(sibling.find(top) == sibling.end()) sibling[top] = 0;
        ++sibling[top];
    }
    
    if(mine.size() == sibling.size()) ++answer;
    
    for(int i = 1, size = topping.size(); i < size; ++i)
    {
        int top = topping[i];
        if(mine.find(top) == mine.end()) mine[top] = 0;
        ++mine[top];
        
        if(--sibling[top] <= 0) sibling.erase(top);
        
        if(mine.size() == sibling.size()) ++answer;
    }
    
    return answer;
}