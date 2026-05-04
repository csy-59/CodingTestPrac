#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    auto s = people.begin();
    auto e = --people.end();
    
    while(s <= e)
    {
        if((*e + *s) <= limit)
        {
            ++s; --e;
            ++answer;
        }
        else
        {
            --e;
            ++answer;
        }
    }
    
    return answer;
}