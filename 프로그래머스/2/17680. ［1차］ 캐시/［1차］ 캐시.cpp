#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int hitTime = 1;
const int missTime = 5;

int solution(int cacheSize, vector<string> cities) {    
    // 캐시가 0이면 무조건 cities 개수 * missTime;
    if(cacheSize == 0) return cities.size() * missTime;
    
    int time = 0;
    
    // 캐시
    unordered_map<string, int> cache;
    
    for(int i = 0, size = cities.size(); i < size; ++i)
    {
        // 도시는 대소문자를 구분하지 않는다
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        // 캐시 히트
        if(cache.find(city) != cache.end())
        {
            time += hitTime;
            cache[city] = time;
            continue;
        }
        
        time += missTime;
        
        // 캐시 미스: 갱신 불필요
        if(cache.size() < cacheSize)
        {
            cache[city] = time;
            continue;
        }
        
        // 캐시 미스: 갱신 필요
        auto lruCity = cache.begin();
        for(auto iter = lruCity; iter != cache.end(); ++iter)
        {
            if(lruCity->second > iter->second)
                lruCity = iter;
        }
        cache.erase(lruCity->first);
        cache[city] = time;
    }
    
    return time;
}