#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int GetTowerCount(vector<vector<bool>>& tree, int startPoint)
{
    int count = 0;
    
    queue<int> q;
    q.push(startPoint);
    
    int size = tree.size();
    vector<bool> isVisited(size, false);
    isVisited[startPoint] = true;
    
    //cout << "(";
    while(q.empty() == false)
    {
        int point = q.front(); q.pop();
        ++count;
        
        //cout << point + 1 << " ";
        
        for(int i = 0; i < size; ++i)
        {
            if(tree[point][i] == true && isVisited[i] == false)
            {
                isVisited[i] = true;
                q.push(i);
            }
        }
    }
    //cout << ")\n";
    
    return count;
}

int GetDiff(vector<vector<bool>>& tree, vector<int> wire)
{
    tree[wire[0] - 1][wire[1] - 1] = false;
    tree[wire[1] - 1][wire[0] - 1] = false;
    
    int a = GetTowerCount(tree, wire[0] - 1);
    int b = GetTowerCount(tree, wire[1] - 1);
    
    //cout << wire[0] << " " << wire[1] << "|" << a << " " << b << "\n";
    int result = abs((a - b));
    
    tree[wire[0] - 1][wire[1] - 1] = true;
    tree[wire[1] - 1][wire[0] - 1] = true;
    
    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int size = wires.size();
    
    // 트리 정리
    vector<vector<bool>> tree(n, vector<bool>(n, false));
    for(int i = 0; i < size; ++i)
    {
        tree[wires[i][0] - 1][wires[i][1] - 1] = true;
        tree[wires[i][1] - 1][wires[i][0] - 1] = true;
    }
    
    int answer = GetDiff(tree, wires[0]);
    for(int i = 1; i < size; ++i)
    {
        answer = min(answer, GetDiff(tree, wires[i]));
    }
    
    return answer;
}