#include <string>
#include <vector>
#include <iostream>

using namespace std;

string GetBinary(int n, int count)
{
    string result = "";
    
    while( n > 0)
    {
        result.insert(0, to_string(n % 2));
        n /= 2;
    }
    
    for(int i = result.size(); i < count; ++i)
    {
        result.insert(0, "0");
    }
    
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    
    for(int i = 0; i < n; ++i)
    {
        string a = GetBinary(arr1[i], n);
        string b = GetBinary(arr2[i], n);
        
        for(int j = 0; j < n; ++j)
        {
            if(a[j] == '0' && b[j] == '0')
            {
                answer[i] += " ";
                continue;
            }
            
            answer[i] += "#";
        }
    }
    
    return answer;
}