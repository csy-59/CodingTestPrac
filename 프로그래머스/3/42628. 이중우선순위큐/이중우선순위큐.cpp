#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> vec;
    
    int vecSize = 0;
    for(int i = 0, size = operations.size(); i < size; ++i)
    {
        string op = operations[i];
        int num = stoi(op.substr(2));
        
        switch(op[0])
        {
            case 'I':
                {
                    ++vecSize;
                    vec.push_back(num);
                    sort(vec.begin(), vec.end());
                    break;
                }
                
            case 'D':
                {
                    if(vecSize <= 0)
                        continue;
                    
                    if(num > 0) vec.erase(vec.end() - 1);
                    else if(num < 0) vec.erase(vec.begin());
                    --vecSize;
                    break;
                }
        }
    }
    
    if(vecSize == 0) { answer.push_back(0); answer.push_back(0);}
    else
    {
        answer.push_back(vec[vecSize - 1]);
        answer.push_back(vec[0]);
    }
    
    return answer;
}