#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> temp;
    
    for(int i = 0, size = operations.size(); i < size; ++i)
    {
        char instruction = operations[i][0];
        int num = stoi(operations[i].substr(2));
        
        switch(instruction)
        {
            case 'I':
                {
                    temp.push_back(num);
                    sort(temp.begin(), temp.end());
                    break;
                }
            case 'D':
                {
                    if(temp.empty() == true) break;
                    
                    if(num == -1) temp.erase(temp.begin());
                    else if(num == 1) temp.pop_back();
                    
                    break;
                }
        }
    }
    
    vector<int> answer;
    if(temp.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(temp[temp.size() - 1]);
        answer.push_back(temp[0]);
    }
    
    return answer;
}