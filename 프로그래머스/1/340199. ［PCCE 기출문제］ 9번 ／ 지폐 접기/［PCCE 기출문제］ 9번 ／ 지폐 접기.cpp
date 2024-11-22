#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int w_width = wallet[0], w_height = wallet[1];
    int b_width = bill[0], b_height = bill[1];
    
    while(true)
    {
        if(w_width >= b_width && w_height >= b_height)
            return answer;
        
        if(w_width >= b_height && w_height >= b_width)
            return answer;
        
        ++answer;
        if(b_width > b_height)
        {
            b_width = (b_width - b_width % 2) / 2;
        }
        else
        {
            b_height = (b_height - b_height % 2) / 2;
        }
    }
    
    return answer;
}