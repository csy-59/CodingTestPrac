#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int size = board.size();
    string color = board[h][w];

    if(h > 0 && board[h -1][w].compare(color) == 0)
        ++answer;
    if(w > 0 && board[h][w-1].compare(color) == 0)
        ++answer;
    if(h < size - 1 && board[h + 1][w].compare(color) == 0)
        ++answer;
    if(w < size - 1 && board[h][w + 1].compare(color) == 0)
        ++answer;
    
    return answer;
}