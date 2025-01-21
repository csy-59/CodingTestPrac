#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

long long GetNodeCount(long long currentSize)
{
    long long size = 1, i = 2;
    while(currentSize > size)
    {
        size = pow(2, i) - 1;
        ++i;
    }
    return size;
}

string GetBinary(long long num)
{
    string result = "";
    
    while(num > 0)
    {
        result.insert(0, to_string(num % 2));
        num /= 2;
    }
    
    long long size = result.size();
    for(long long i = 0, count = GetNodeCount(size) - size; i < count; ++i)
    {
        result.insert(0, "0");
    }
    
    return result;
}

bool isTree(string code)
{
    int size = code.size();
    if(code[size / 2] == '0')
    {
        if(size <= 1)
            return false;
        
        for(int i = 0; i < size; ++i)
        {
            if(code[i] == '1')
                return false;
        }
        
        return true;
    }
    
    if(size > 3)
    {
        if(isTree(code.substr(0, size / 2)) && isTree(code.substr(size / 2 + 1)))
            return true;
        
        return false;
    }
    
    return true;
}

int a[] = {0, 1, 1,1,0,0,1,1,1,0,1,1,0,0,1,1,0,1,0,0,1};

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i = 0, size = numbers.size(); i < size; ++i)
    {
        string b = GetBinary(numbers[i]);
        answer.push_back(isTree(b) == true ? 1 : 0);
        //cout << b << " >> " << answer[answer.size() - 1] << 
        //    " | " << (answer[answer.size() - 1] == a[i] ? "O" : "X") << endl;
    }
    
    return answer;
}