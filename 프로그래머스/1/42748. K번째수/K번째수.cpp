#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0, size = commands.size(); i < size; ++i)
    {
        vector<int> arr(array);
        vector<int>& c = commands[i];
        sort(&arr[c[0] - 1], &arr[c[1]]);
        answer.push_back(arr[c[0] + c[2] - 2]);
    }
    
    return answer;
}