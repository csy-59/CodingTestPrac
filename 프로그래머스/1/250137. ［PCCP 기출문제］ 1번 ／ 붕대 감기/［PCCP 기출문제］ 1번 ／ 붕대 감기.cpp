#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int hp = health;
    int time = 1;
    for(int i = 0, size = attacks.size() ; i < size; ++i)
    {
        vector<int> ack = attacks[i];
        
        int offsetTime = ack[0] - time;
        int addHp = offsetTime * bandage[1] + offsetTime / bandage[0] * bandage[2];
        hp += addHp;
        if(hp > health) hp = health;
        
        hp -= ack[1];
        if(hp <= 0)
            return -1;
        
        time = ack[0] + 1;
    }
    
    return hp;
}