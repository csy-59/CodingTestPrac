#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    if(arr.size() <= 1)
    {
        vector<int> answer;
        answer.push_back(-1);
        return answer;
    }
    
    int index = 0;
    unsigned int min = arr[0];
    for(int i = 1, size = arr.size(); i < size; ++i)
    {
        if(min > arr[i])
        {
            min = arr[i];
            index = i;
        }
    }
    
    vector<int> answer(arr);
    answer.erase(answer.begin() + index);
    
    return answer;
}