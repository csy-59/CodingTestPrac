#include <string>
#include <vector>

using namespace std;

int s = 0;
int t;

int dfs(vector<int>& nums, int index, int total)
{
    if(index == s)
        return total == t ? 1 : 0;
    
    return dfs(nums, index + 1, total + nums[index]) +
        dfs(nums, index + 1, total - nums[index]);
}

int solution(vector<int> numbers, int target) {
    t = target;
    s = numbers.size();
    
    return dfs(numbers, 0, 0);
}