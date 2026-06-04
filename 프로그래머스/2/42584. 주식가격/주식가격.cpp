#include <string>
#include <vector>
#include <stack>

using namespace std;

struct stock{
    int price;
    int time;
    
    stock() { price = time = 0; }
    stock(int p, int t): price(p), time(t) {}
};

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    
    vector<int> answer(size, 0);
    
    stack<stock> s;
    stock st(prices[0], 0);
    s.push(st);
    
    for(int i = 1; i < size; ++i)
    {
        while(s.empty() == false && s.top().price > prices[i])
        {
            stock st = s.top(); s.pop();
            answer[st.time] = i - st.time;
        }
        stock st(prices[i], i);
        s.push(st);
    }
    
    while(s.empty() == false)
    {
        stock st = s.top(); s.pop();
        answer[st.time] = size - st.time - 1;
    }
    
    return answer;
}