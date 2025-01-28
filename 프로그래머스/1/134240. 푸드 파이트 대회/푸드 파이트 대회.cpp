#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    answer.push_back('0');
    for(int i = food.size() - 1; i >= 0; --i)
    {
        int count = food[i] / 2;
        string f;
        for(int j = 0; j < count; ++j)
        {
            f.push_back('0' + i);
        }
        answer += f;
        answer.insert(0, f);
    }
    
    return answer;
}