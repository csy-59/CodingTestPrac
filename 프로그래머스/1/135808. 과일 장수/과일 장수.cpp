#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), cmp);
    
    int size = score.size();
    int index = m - 1;
    while(index < size)
    {
        answer += score[index] * m;
        index += m;
    }
    
    return answer;
}