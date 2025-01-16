#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    queue<int> q;
    vector<int> m(n);
    vector<vector<bool>> e(n, vector<bool>(n, false));
    for(int i = 0; i < n; ++i)
    {
        m[i] = -1;
    }
    m[0] = 0;
    
    for(int i = 0, size = edge.size(); i < size; ++i)
    {
        vector<int> ed = edge[i];
        int a = ed[0] - 1;
        int b = ed[1] - 1;
        e[a][b] = true;
        e[b][a] = true;
        
        if(a == 0) { m[b] = 1; q.push(b); }
        else if(b == 0) { m[a] = 1; q.push(a); }
    }
    
    while(q.empty() == false)
    {
        int num = q.front();
        q.pop();
        
        for(int i = 1; i < n; ++i)
        {
            if(e[num][i] == false) continue;
            
            if(m[i] == -1 || m[i] > m[num] + 1)
            {
                m[i] = m[num] + 1;
                q.push(i);
            }
        }
    }
    
    int count = 0;
    int max = -1;
    for(int i = 0; i < n; ++i)
    {
        cout << m[i] << endl;
        if(m[i] > max)
        {
            max = m[i];
            count = 1;
        }
        
        else if(m[i] == max)
        {
            ++count;
        }
    }
    
    return count;
}