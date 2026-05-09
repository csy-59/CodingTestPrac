#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> ans;
    
    int sqY = sqrt(yellow);
    for(int i = 1; i < sqY + 1; ++i)
    {
        if(yellow % i == 0 && (i + yellow / i) * 2 + 4 == brown)
        {
            ans.push_back(yellow / i + 2);
            ans.push_back(i + 2);
            return ans;
        }
    }
    
    return ans;
}