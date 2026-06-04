#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    // 각 행렬의 행 열 길이
    int a1R = arr1.size(); // arr1의 행 개수
    int k = arr1[0].size(); // arr1의 열 개수(arr2의 행 개수)
    int a2C = arr2[0].size(); // arr2의 열 개수
    
    for(int x = 0; x < a1R; ++x)
    {
        vector<int> row(a2C, 0);
        for(int i = 0; i < a2C; ++i)
        {
            for(int j = 0; j < k; ++j)
            {
                row[i] += arr1[x][j] * arr2[j][i];
            }
        }
        answer.push_back(row);
    }
    
    return answer;
}