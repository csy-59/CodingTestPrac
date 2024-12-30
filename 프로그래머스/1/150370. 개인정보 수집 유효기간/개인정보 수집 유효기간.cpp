#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> Split_Date(string date)
{
    vector<int> result(3);
    result[0] = stoi(date.substr(0,4));
    result[1] = stoi(date.substr(5,2));
    result[2] = stoi(date.substr(8,2));
    
    return result;
}

vector<string> Split_Privacie(string privacie)
{
    vector<string> result(2);
    result[0] = privacie.substr(0,10);
    result[1] = privacie.substr(11, 1);
    
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<int> todayDate = Split_Date(today);
    unordered_map<string, int> m;
    
    for(int i = 0, size = terms.size(); i < size; ++i)
    {
        m[terms[i].substr(0, 1)] = stoi(terms[i].substr(2, 3));
    }
    
    for(int i = 0, size = privacies.size(); i < size; ++i)
    {
        vector<string> p = Split_Privacie(privacies[i]);
        vector<int> date = Split_Date(p[0]);
        
        date[1] += m[p[1]];
        --date[2];
        if(date[2] <= 0)
        {
            --date[1];
            if(date[1] <= 0)
            {
                --date[0];
                date[1] = 12;
            }
            date[2] = 28;
        }
        
        while( date[1] > 12)
        {
            ++date[0];
            date[1] -= 12;
        }
        
        for(int j = 0; j < 3; ++j)
        {
            if(todayDate[j] < date[j])
            {
                break;
            }
            else if(todayDate[j] > date[j])
            {
                answer.push_back(i + 1);
                break;
            }
        }
    }
    
    return answer;
}