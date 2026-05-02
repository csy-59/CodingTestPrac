#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), less<>());
    sort(B.begin(), B.end(), less<>());
    
    auto aPoint = A.begin();
    auto bPoint = B.begin();
    
    while(aPoint != A.end() && bPoint != B.end())
    {
        if(*aPoint < *bPoint)
        {
            ++aPoint; ++bPoint;
            ++answer;
        }
        else
        {
            ++bPoint;
        }
    }
    
    return answer;
}