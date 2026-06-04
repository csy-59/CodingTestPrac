#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sumOfHnW = brown / 2 + 2;
    
    for(int i = 3; i <= sumOfHnW - 3; ++i) // 최소 길이는 3
    {
        int h = i, w = sumOfHnW - h;
        if(yellow == (h - 2) * (w - 2))
        {
            answer.push_back(w);
            answer.push_back(h);
            return answer;
        }
    }
    
    return answer;
}