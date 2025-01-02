#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int pSize = p.size();
    for(int i = 0, size = t.size() - pSize; i <= size; ++i)
    {
        string temp = t.substr(i, pSize);
        answer += temp <= p ? 1 : 0;
    }
    
    return answer;
}