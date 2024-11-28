#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    answer.reserve(photo.size());
    
    unordered_map<string, int> memory;
    for(int i = 0, size = name.size(); i < size; ++i)
    {
        memory[name[i]] = yearning[i];
    }
    
    for(vector<string> p : photo)
    {
        int m = 0;
        for(string n : p)
        {
            if(memory.find(n) != memory.end())
                m += memory[n];
        }
        answer.push_back(m);
    }
    
    return answer;
}