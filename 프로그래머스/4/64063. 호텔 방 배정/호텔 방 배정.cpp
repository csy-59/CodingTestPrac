#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> parent;

long long findRoom(long long x)
{
    if (parent.find(x) == parent.end())
    {
        parent[x] = x + 1;
        return x;
    }

    return parent[x] = findRoom(parent[x]);
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;
    answer.reserve(room_number.size());

    for (int i = 0; i < (int)room_number.size(); ++i)
    {
        long long room = findRoom(room_number[i]);
        answer.push_back(room);
    }

    return answer;
}