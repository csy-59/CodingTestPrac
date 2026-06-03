#include <string>
#include <vector>
#include <map>

using namespace std;

int ticketCount;
vector<int> candidate;

bool BT(vector<vector<int>>& map, vector<int>& road)
{
    if(road.size() == ticketCount + 1)
    {
        candidate = road;
        return true;
    }
    
    int lastStop = road[road.size() - 1];
    for(int i = 0, size = map[lastStop].size(); i < size; ++i)
    {
        if(map[lastStop][i] > 0)
        {
            --map[lastStop][i];
            road.push_back(i);
            
            if(BT(map, road) == true)
            {
                return true;
            }
            
            road.pop_back();
            ++map[lastStop][i];
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    const string ICN = "ICN";
    
    ticketCount = tickets.size();
    
    // 각 목적지에 대한 인덱스
    map<string, int> airportMap;
    for(int i = 0; i < ticketCount; ++i)
    {
        airportMap[tickets[i][0]] = 0;
        airportMap[tickets[i][1]] = 0;
    }
    
    vector<string> airportNames(airportMap.size(), "");
    int num = 0;
    for(auto iter = airportMap.begin(); iter != airportMap.end(); ++iter)
    {
        airportNames[num] = iter->first;
        iter->second = num; ++num;
    }
    
    // 연결된 항공로에 대한 표기
    int airportCount = airportNames.size();
    vector<vector<int>> roadMap(airportCount, vector<int>(airportCount, 0));
    for(int i = 0; i < ticketCount; ++i)
    {
        ++roadMap[airportMap[tickets[i][0]]][airportMap[tickets[i][1]]];
    }
    
    // 연산
    vector<int> road;
    road.push_back(airportMap[ICN]);
    BT(roadMap, road);
    
    // 결과 정리
    for(int i = 0, size = candidate.size(); i < size; ++i)
    {
        answer.push_back(airportNames[candidate[i]]);
    }
    
    return answer;
}