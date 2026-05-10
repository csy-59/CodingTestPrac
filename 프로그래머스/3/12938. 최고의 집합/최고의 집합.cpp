#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> result;
    
    if(s / n == 0)
    {
        result.push_back(-1);
        return result;
    }
    
    if(s % n == 0)
    {
        int ans = s / n;
        for(int i = 0; i < n; ++i)
        {
            result.push_back(ans);
        }
    }
    else
    {
        int ans = s / n;
        int remain = s % n;
        for(int i = 0; i < n - remain; ++i)
        {
            result.push_back(ans);
        }
        for(int i = 0; i < remain; ++i)
        {
            result.push_back(ans + 1);
        }
    }
    
    return result;
}