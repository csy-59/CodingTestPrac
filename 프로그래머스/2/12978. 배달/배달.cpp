#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long MAX = 2000 * 10000 + 1;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // 맵 설정
    vector<vector<long long>> graph(N, vector<long long>(N, -1));
    for(int i = 0, size = road.size(); i < size; ++i)
    {
        int s = road[i][0] - 1, e = road[i][1] - 1;
        int cost = road[i][2];
        
        if(graph[s][e] == -1) 
            graph[s][e] = graph[e][s] = (long long) cost;
        else
            graph[s][e] = graph[e][s] = min(graph[s][e], (long long)cost);
    }
    
    vector<long long> dist(N, MAX);
    dist[0] = 0;
    
    priority_queue<
        pair<int, int>, 
        vector<pair<int,int>>,
        greater<pair<int,int>>> q;
    q.push({0, 0});
    
    while(q.empty() == false)
    {
        int curCost = q.top().first;
        int curTown = q.top().second; 
        q.pop();
        
        if(curCost > dist[curTown])
            continue;
        
        for(int i = 0; i < N; ++i)
        {
            if(graph[curTown][i] == -1) continue;
            
            if(dist[i] > graph[curTown][i] + curCost)
            {
                dist[i] = graph[curTown][i] + curCost;
                pair<int, int> newNode({dist[i], i});
                q.push(newNode);
            }
        }
    }
    
    for(int i = 0; i < N ; ++i)
    {
        if(dist[i] <= K) ++answer;
    }

    return answer;
}