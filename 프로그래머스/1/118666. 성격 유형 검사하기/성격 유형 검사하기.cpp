#include <string>
#include <vector>

using namespace std;

int GetPos(char c)
{
    switch(c)
    {
        case 'R': return 0;
        case 'T': return 1;
        case 'C': return 10;
        case 'F': return 11;
        case 'J': return 20;
        case 'M': return 21;
        case 'A': return 30;
        case 'N': return 31;
    }
}

char GetType(char a, char b, int aValue, int bValue)
{
    if(aValue >= bValue) return a;
    return b;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    int result[4][2] = { 0 };
    
    for(int i = 0, size = survey.size(); i < size; ++i)
    {
        int a = GetPos(survey[i][0]);
        int b = GetPos(survey[i][1]);
        
        int v = choices[i] - 4;
        
        if(v > 0) result[b/10][b%10] += v;
        else if(v < 0) result[a/10][a%10] -= v;
    }
    
    answer += GetType('R', 'T', result[0][0], result[0][1]);
    answer += GetType('C', 'F', result[1][0], result[1][1]);
    answer += GetType('J', 'M', result[2][0], result[2][1]);
    answer += GetType('A', 'N', result[3][0], result[3][1]);
    
    return answer;
}