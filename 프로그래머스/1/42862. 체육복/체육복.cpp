#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n, 0);
    
    for(int i = 0, size = lost.size(); i < size; ++i)
        --students[lost[i] - 1];
    
    for(int i = 0, size = reserve.size(); i < size; ++i)
        ++students[reserve[i] - 1];
    
    for(int i = n - 1; i >= 0; --i)
    {
        if(students[i] >= 0) 
        {
            ++answer;
            continue;
        }
        
        if(i + 1 < n && students[i + 1] > 0)
        {
            ++students[i]; --students[i + 1];
        }
        else if(i - 1 >= 0 && students[i - 1] > 0)
        {
            ++students[i]; --students[i - 1];
        }
        
        if(students[i] == 0)
            ++answer;
    }
    
    
    
    return answer;
}