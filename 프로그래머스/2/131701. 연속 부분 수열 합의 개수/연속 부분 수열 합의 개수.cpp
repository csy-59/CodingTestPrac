#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    
    unordered_set<int> s;
    
    for(int i = 0, size = elements.size(); i < size; ++i)
    {
        int sum = 0;
        for(int j = 0; j < size; ++j)
        {
            sum += elements[(i + j) % size];
            s.insert(sum);
        }
    }
    
    return s.size();
}