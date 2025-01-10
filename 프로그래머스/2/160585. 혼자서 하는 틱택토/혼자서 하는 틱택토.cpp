#include <string>
#include <vector>

using namespace std;

bool Search(vector<string>& board, char target)
{
    for(int i = 0; i < 3; ++i)
    {
        if(board[0][i] == target && board[1][i] == target && board[2][i] == target)
            return true;
        
        if(board[i][0] == target && board[i][1] == target && board[i][2] == target)
            return true;
    }
    
    if(board[0][0] == target && board[1][1] == target &&  board[2][2] == target)
        return true;
    
    if(board[0][2] == target && board[1][1] == target && board[2][0] == target)
        return true;
    
    return false;
}

int solution(vector<string> board) {
    int oCnt = 0;
    int xCnt = 0;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(board[i][j] == 'O') ++oCnt;
            else if(board[i][j] == 'X') ++xCnt;
        }
    }
    
    if(xCnt > oCnt) return 0;
    else if(xCnt + 1 < oCnt) return 0;
    
    bool xWin = Search(board, 'X');
    bool oWin = Search(board, 'O');
    if(xWin && oWin) return 0;
    if(xWin && oCnt != xCnt) return 0;
    if(oWin && oCnt <= xCnt) return 0;
    
    return 1;
}