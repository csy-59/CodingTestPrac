#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    
    int min = score[0];
    answer.push_back(min);
    temp.push_back(min);
    
    for(int i = 1, size = score.size(); i < size; ++i)
    {
        int num = score[i];
        if(answer.size() < k)
        {
            temp.push_back(num);
            sort(temp.begin(), temp.end());
            min = temp[0];
        }        
        else if(num > min)
        {
            temp[0] = num;
            sort(temp.begin(), temp.end());
            min = temp[0];
        }
        
        answer.push_back(min);
    }
    
    return answer;
}