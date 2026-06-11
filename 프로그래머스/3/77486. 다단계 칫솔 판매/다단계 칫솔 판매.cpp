#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    
    unordered_map<string, int> map;
    for(int i = 0, size = enroll.size(); i < size; ++i)
    {
        map[enroll[i]] = i;
    }
    
    for(int i = 0, size = seller.size(); i < size; ++i)
    {
        string s = seller[i];
        int a = amount[i] * 100;
        int profit = 0;
        
        do {
            profit = (int)floor(a * 0.1);
            answer[map[s]] += a - profit;
            s = referral[map[s]];
            a = profit;
        } while(s != "-" && a > 0);
    }
    
    return answer;
}