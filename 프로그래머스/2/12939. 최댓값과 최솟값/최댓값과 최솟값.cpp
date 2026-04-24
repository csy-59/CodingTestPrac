#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    
    bool isInitialized = false;
    int low = 0;
    int high = 0;
    for(int i = 0, size = s.size(); i < size; ++i)
    {
        if(s[i] == ' ')
        {
            int t = stoi(temp);
            if(isInitialized == true)
            {
                low = min(low, t);
                high = max(high, t);
            }
            else
            {
                low = high = t;
                isInitialized = true;
            }
            temp = "";
            continue;
        }
        
        temp += s[i];
    }
    
    int t = stoi(temp);
    low = min(low, t);
    high = max(high, t);
    
    answer += to_string(low);
    answer += " ";
    answer += to_string(high);
    return answer;
}