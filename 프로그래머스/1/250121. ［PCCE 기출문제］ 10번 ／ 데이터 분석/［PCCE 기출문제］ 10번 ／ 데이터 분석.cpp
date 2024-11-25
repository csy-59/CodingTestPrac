#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sort_colum = 0;

bool cmp(vector<int> a, vector<int> b)
{
    return a[sort_colum] < b[sort_colum];
}

int GetColumIndex(string str)
{
    int result = 0;
    switch(str[0])
    {
        case 'c': result = 0; break;
        case 'd': result = 1; break;
        case 'm': result = 2; break;
        case 'r': result = 3; break;
    }
    return result;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int ext_colum = GetColumIndex(ext);
    sort_colum = GetColumIndex(sort_by);
    
    for(int i = 0, size = data.size(); i < size; ++i)
    {
        if(data[i][ext_colum] < val_ext)
            answer.push_back(data[i]);
    }
    
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}