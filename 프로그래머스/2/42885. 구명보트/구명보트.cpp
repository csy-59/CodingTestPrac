#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    auto s = people.begin();
    auto e = people.end() - 1;
    
    while(s <= e)
    {
        if(*s + *e <= limit)
        {
            ++s; --e;
            ++answer;
        }
        else
        {
            --e; ++answer;
        }
    }
    
    return answer;
}