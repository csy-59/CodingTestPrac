#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0, height = 0;
    for(int i = 0, size = sizes.size(); i < size; ++i)
    {
        vector<int>& card = sizes[i];
        int w = card[0] > card[1] ? card[0] : card[1];
        int h = card[0] < card[1] ? card[0] : card[1];
        
        width = w > width ? w : width;
        height = h > height ? h : height;
    }
    
    return width * height;
}