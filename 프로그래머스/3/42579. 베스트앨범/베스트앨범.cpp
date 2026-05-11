#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class g{
    public:

    int total = 0;
    vector<int> index;
    
    g(): total(0) { };
};

vector<int> p;

bool cmp(int a, int b)
{
    if(p[a] != p[b])
        return p[a] > p[b];
    return a < b;
}

bool gCmp(g& a, g& b)
{
    return a.total > b.total;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    p = plays;
    unordered_map<string, g> m;
    
    for(int i = 0, size = genres.size(); i < size; ++i)
    {
        string g = genres[i];
        if(m.find(g) != m.end())
        {
            m[g].total += plays[i];
            m[g].index.push_back(i);
        }
        else
        {
            m[g].total = plays[i];
            m[g].index.push_back(i);
        }
    }
    
    vector<g> t;
    
    for (auto iter = m.begin(); iter != m.end(); ++iter)
    {
        t.push_back(iter->second);
    }
    
    sort(t.begin(), t.end(), gCmp);
    
    for(int i = 0, size = t.size(); i < size; ++i)
    {
        sort(t[i].index.begin(), t[i].index.end(), cmp);
        int j = 0;
        while(j < 2 && j < t[i].index.size())
        {
            answer.push_back(t[i].index[j]);
            ++j;
        }
    }
    
    return answer;
}