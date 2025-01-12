#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> s;
    
    for(int i = 0, size = nums.size(); i < size; ++i)
    {
        s.insert(nums[i]);
    }
    
    int size = s.size();
    
    answer = nums.size()/2 < size ? nums.size()/2 : size;
    
    return answer;
}